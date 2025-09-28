#include "so_long.h"

int    close_win(t_game *data)
{
        exit_game(data);
        return (0);
}

void print_char(char c)
{
    write(1, &c, 1);
}

void print_int(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (n < 0) {
        print_char('-');
        n = -n;
    }
    if (n >= 10) {
        print_int(n / 10);
    }
    print_char(n % 10 + '0');
}

int key_hook(int keycode, t_game *data)
{
    if (keycode == 119)
        move_player(data->map, data, 0, -1);
    else if (keycode == 97)
        move_player(data->map, data, -1, 0);
    else if (keycode == 115)
        move_player(data->map, data, 0, 1);
    else if (keycode == 100)
        move_player(data->map, data, 1, 0);
    else if (keycode == 65307)
        close_win(data);
    return (0);
}