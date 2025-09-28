#include "so_long.h"

void    close_win(t_game *data)
{
        exit_game(data);
}

int key_hook(int keycode, t_game *data)
{
    if (keycode == 119)
        player_pos(data->map, data, 0, -1);
    else if (keycode == 97)
        player_pos(data->map, data, -1, 0);
    else if (keycode == 115)
        player_pos(data->map, data, 0, 1);
    else if (keycode == 100)
        player_pos(data->map, data, 1, 0);
    else if (keycode == 65307)
        close_win(data);
    return (0);
}