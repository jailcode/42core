#include "so_long.h"

char    *ft_strdup(char *s)
{
    char    *dup;
    int     len;
    int     i;
    
    len = 0;
    while(s[len])
        len++;
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while(i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

void    free_map(t_game *data)
{
    int i;

    i = 0;
    while (i < data->map->rows + 1)
    {
        free(data->map->map[i]);
        i++;
    }
    free(data->map->map);
}

void exit_game(t_game *data)
{
    int i;

    i = 0;
     while (i < 5)
    {
        if (data->map->sprites[i])
            mlx_destroy_image(data->mlx, data->map->sprites[i]);
        i++;
    }
    if (data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
        mlx_destroy_display(data->mlx);
    
    free_map(data);
    free_gnl_buffers();
    exit(0);
}