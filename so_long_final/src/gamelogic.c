/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamelogic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:26:10 by pdangwal          #+#    #+#             */
/*   Updated: 2025/09/29 13:26:44 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_collectables(t_map *map)
{
	int	i;
	int	j;
	int	collectables;

	collectables = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'C')
				collectables++;
			j++;
		}
		i++;
	}
	return (collectables);
}

int	player_pos(t_map *map, t_game *data, int x, int y)
{
	int	current_x;
	int	current_y;
	int	c;

	c = find_collectables(map);
	current_x = data->playerpos[0];
	current_y = data->playerpos[1];
	if (map->map[current_y + y][current_x + x] != '1')
	{
		data->playerpos[0] += x;
		data->playerpos[1] += y;
		if (map->map[current_y + y][current_x + x] == 'C')
			c--;
		if (map->map[current_y][current_x] != 'E')
			map->map[current_y][current_x] = '0';
		if (map->map[current_y + y][current_x + x] == 'E' && c == 0)
			exit_game(data);
		if (map->map[current_y + y][current_x + x] == 'E' && c > 0)
			return (0);
		map->map[current_y + y][current_x + x] = 'P';
		game_update(data);
		return (1);
	}
	return (0);
}

void	move_player(t_map *map, t_game *data, int x, int y)
{
	if (player_pos(map, data, x, y))
	{
		data->moves++;
		write(1, "moves: ", 7);
		print_int(data->moves);
		write(1, "\n", 1);
	}
}

int	game_update(t_game *data)
{
	mlx_clear_window(data->mlx, data->win);
	map_loader(data->map, data);
	return (0);
}
