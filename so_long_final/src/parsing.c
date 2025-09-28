#include "so_long.h"

void	return_error(t_game *data)
{
    write(1, "Error\n", 6);
    exit_game(data);
}

static int col_finder(t_map *map, char *filename)
{
    int		fd;
    char	*line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (0);
    }
    line = get_next_line(fd);
    if (line != NULL)
    {
        map->cols = ft_strlen(line);
        if (line[map->cols - 1] == '\n') // Adjust for newline
            map->cols--;
        free(line);
    }
    close(fd);
    return (1);
}

static int row_finder(t_map *map, char *filename)
{
    int		fd;
    int		i;
    char	*line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (0);
    }
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (line == NULL)
            break;
        free(line);
        i++;
    }
    map->rows = i;
    close(fd);
    return (1);
}

int readmaptwo(t_map *map, t_game *data, int fd)
{
	    int		i;

    map->map = malloc((map->rows + 1) * sizeof(char *));
    if (map->map == NULL)
        return_error(data);
    i = 0;
    while (i < map->rows)
    {
        map->line = get_next_line(fd);
        if (!map->line)
        	break;
        if ((int)ft_strlen(data->map->line) - 
		(map->line[ft_strlen(map->line) - 1] == '\n') != map->cols)
        {
            free(map->line);
			return (0);
        }
        map->map[i] = ft_strdup(map->line);
        free(map->line);
        i++;
    }
    map->map[i] = NULL; // Null-terminate the map array
    close(fd);
    return (1);
}

int	readmap(t_map *map, t_game *data, char *filename)
{
    int		fd;

    if (!row_finder(map, filename) || !col_finder(map, filename))
        return (0);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (0);
    }
	if (!readmaptwo(map, data, fd))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

