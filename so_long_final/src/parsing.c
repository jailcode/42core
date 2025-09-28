
#include "so_long.h"

static int col_finder(t_map *map, char *filename)
{
	int	fd;
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
		map->cols = ft_strlen(line) - 1; // since last is null it just sets to one.
		free(line);
	}
	close(fd);
	return (1);
}
//row finder seems to always give atleast one due to the file having one line
static int row_finder(t_map *map, char *filename)
{
	int	fd;
	int	i;
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

int	readmap(t_map *map, char *filename)
{
	int	fd;
	int	i;
	char	*line;

	row_finder(map, filename);
	col_finder(map, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	i = 0;
	map->map = malloc((map->rows + 1)* sizeof(char *));
	while (i < map->rows)
	{
		line = get_next_line(fd);
		map->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
	return (1);
}

