/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifymap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:27:53 by pdangwal          #+#    #+#             */
/*   Updated: 2025/09/29 13:27:56 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	define_values(t_map *map, t_game *data)
{
	int	i;
	int	j;

	map->c = 0;
	map->e = 0;
	map->p = 0;
	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
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

int	is_rectangular(t_map *map)
{
	int	i;
	int	len;

	i = 0;
	while (map->map[i] && i < map->rows)
	{
		len = ft_strlen(map->map[i]);
		if (map->map[i][len - 1] == '\n')
			len--;
		if (len != map->cols)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_covered(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows && map->map[i])
	{
		j = 0;
		while (j < map->cols && map->map[i][j])
		{
			if ((i == 0 || j == 0 || i == map->rows - 1 || j == map->cols - 1)
				&& map->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_elements(t_map *map, t_game *data)
{
	int	i;
	int	j;

	i = 0;
	define_values(map, data);
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
				map->p++;
			else if (map->map[i][j] == 'E')
				map->e++;
			else if (map->map[i][j] == 'C')
				map->c++;
			j++;
		}
		i++;
	}
	if (map->p != 1 || map->e != 1 || map->c < 1)
		return (0);
	return (1);
}

int	verify_all(t_map *map, t_game *data)
{
	if (!is_rectangular(map))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_covered(map))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!check_elements(map, data))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	define_values(map, data);
	if (!valid_path(map, data->playerpos[0], data->playerpos[1]))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}
