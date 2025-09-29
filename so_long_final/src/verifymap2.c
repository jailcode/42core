/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifymap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:28:03 by pdangwal          #+#    #+#             */
/*   Updated: 2025/09/29 13:36:43 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(t_map *map, int **visited, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->rows || y >= map->cols)
		return ;
	if (map->map[x][y] == '1' || visited[x][y])
		return ;
	visited[x][y] = 1;
	flood_fill(map, visited, x + 1, y);
	flood_fill(map, visited, x - 1, y);
	flood_fill(map, visited, x, y + 1);
	flood_fill(map, visited, x, y - 1);
}

static int	**alloc_visited(t_map *map)
{
	int	**visited;
	int	i;

	visited = malloc(sizeof(int *) * map->rows);
	if (!visited)
		return (NULL);
	i = 0;
	while (i < map->rows)
	{
		visited[i] = ft_calloc(map->cols, sizeof(int));
		if (!visited[i])
			return (NULL);
		i++;
	}
	return (visited);
}

static int	check_reachables(t_map *map, int **visited)
{
	int	j;
	int	i;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if ((map->map[i][j] == 'C' || map->map[i][j] == 'E')
				&& !visited[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	free_visited(int **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

int	valid_path(t_map *map, int px, int py)
{
	int	ok;
	int	**visited;

	visited = alloc_visited(map);
	if (!visited)
		return (0);
	flood_fill(map, visited, px, py);
	ok = check_reachables(map, visited);
	free_visited(visited, map->rows);
	return (ok);
}
