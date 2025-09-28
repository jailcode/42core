#include "so_long.h"


void    player_pos(t_map *map, t_game *data, int x, int y)
{
    int current_x;
    int current_y;

    current_x = data->playerpos[0];
    current_y = data->playerpos[1];

    if (map->map[current_y + y][current_x + x] != '1')
        {
            data->playerpos[0] += x;
            data->playerpos[1] += y;
            map->map[current_y][current_x] = '0';
            if (map->map[current_y + y][current_x + x] == 'E')
                {
                    printf("YOU DID IT YAYYY\n");
                    exit_game(data);
                    return ;
                }
            map->map[current_y + y][current_x + x] = 'P';
            game_update(data);
        }
}
int game_update(t_game *data)
{
    mlx_clear_window(data->mlx, data->win);
    map_loader(data->map, data);
    return (0);
}