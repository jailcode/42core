
#include "so_long.h"

void define_values(t_map *map, t_game *data)
{
    int i;
    int j;

    map->c = 0;
    map->e = 0;
    map->p = 0;
    i = 0;
    while(map->map[i])
    {
        j = 0;
        while(map->map[i][j])
        {
            if (map->map[i][j] == 'P')
            {
                data->playerpos[0] = j;
                data->playerpos[1] = i;
            }
            j++;
        }
        i++;
    }
}

int is_rectangular(t_map *map)
{
    int i;
    int len;
    
    i = 0;
    while (i < map->rows)
    {   
        len = ft_strlen(map->map[i]); // this is 0 for some reason
        if (map->map[i][len - 1] == '\n')
            len--;
        printf("\nthis is len: %d\n", len);
        if (len != map->cols)
        {
            printf("\nlen: %d and col: %d\n", len, map->cols);
                return (0);
        }
        i++;
    }
    return (1);
}
int is_covered(t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->rows && map->map[i])
    {
        j = 0;
        
        while (j < map->cols && map->map[i][j])
        {
            if ((i == 0 || j == 0 || i == map->rows - 1
                || j == map->cols - 1) && map->map[i][j] != '1')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int check_elements(t_map *map, t_game *data)
{
    int i;
    int j;

    i = 0;
    define_values(map, data);
    while (i < map->rows)
    {
        j = 0;
        while (j < map->cols)
        {
            if (map->map[i][j] == 'P')
                (map->p)++;
            else if (map->map[i][j] == 'E')
                (map->e)++;
            else if (map->map[i][j] == 'C')
                (map->c)++;
            j++; 
        }
        i++;
    }
    if (map->p != 1 || map->e != 1 || map->c < 1)
        return (0);
    return (1);
}

int verify_all(t_map *map, t_game *data)
{
    printf("verify all in action\n");
    
    if (!is_rectangular(map))
        return (0);
    printf("rect works\n");
    if (!is_covered(map))
        return (0);
    printf("is covered\n");

    if (!check_elements(map, data))
        return (0);
    printf("elements check out\n");
    define_values(map, data);
    printf("values definnied\n");
    if (!valid_path(map, data->playerpos[0], data->playerpos[1]))
        return (0);
    return (1);
}