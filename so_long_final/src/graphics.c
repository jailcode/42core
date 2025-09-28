#include "so_long.h"


void    init_conn(t_map *map, t_game *data)
{
    int xsize;
    int ysize;

    xsize = map->cols;
    ysize = map->rows;

    map->c = 0;
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        printf("mlx init has failed\n");
        exit(1);
    }
    data->win = mlx_new_window(data->mlx, (xsize)* 32,(ysize)* 32, "game :D");
    if (!data->win)
    {
        printf("window creation failed\n");
        exit(1);
    }
}

void load_sprites(t_map *map, t_game *data)
{
    map->sprites[0] = mlx_xpm_file_to_image(data->mlx, "src/assets/2.xpm", &(map->s), &(map->s));
    map->sprites[1] = mlx_xpm_file_to_image(data->mlx, "src/assets/4.xpm", &(map->s), &(map->s));
    map->sprites[2] = mlx_xpm_file_to_image(data->mlx, "src/assets/3.xpm", &(map->s), &(map->s));
    map->sprites[3] = mlx_xpm_file_to_image(data->mlx, "src/assets/3.xpm", &(map->s), &(map->s));
    map->sprites[4] = mlx_xpm_file_to_image(data->mlx, "src/assets/3.xpm", &(map->s), &(map->s));
}

void *assets(t_map *map, char c)
{
    if (c == '1')
        return (map->sprites[0]);
    else if (c == '0')
        return (map->sprites[1]);
    else if (c == 'E')
        return (map->sprites[2]);
    else if (c == 'C')
        return (map->sprites[3]);
    else if (c == 'P')
        return (map->sprites[4]);
    return (NULL);
}


void render_tile(t_map *map, t_game *data, int x, int y)
{
    int i;
    int j;
    
    i = y * 32;
    j = x * 32;
    mlx_put_image_to_window(data->mlx, data->win, assets(map, '0'), j, i);
    if (map->map[y][x] == '1')
        mlx_put_image_to_window(data->mlx, data->win, assets(map, '1'), j, i);
    else if (map->map[y][x] == 'C')
        mlx_put_image_to_window(data->mlx, data->win, assets(map, 'C'), j, i);
    else if (map->map[y][x] == 'E')
        mlx_put_image_to_window(data->mlx, data->win, assets(map, 'E'), j, i);
    else if (map->map[y][x] == 'P')
        mlx_put_image_to_window(data->mlx, data->win, assets(map, 'P'), j, i);
}

void map_loader(t_map *map, t_game *data)
{
    int i;
    int j;
    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {

            render_tile(map, data, j, i);
            j++;
        }
        i++;
    }
}


void play_game(t_map *map, t_game *data)
{
    static int steps;

    steps = 0;
    init_conn(map, data);
    load_sprites(map, data);
    map_loader(map, data);
    mlx_hook(data->win, 17, 0, close_win, data);
    mlx_key_hook(data->win, key_hook, data);
    mlx_loop(data->mlx);
}