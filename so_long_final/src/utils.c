/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:27:43 by pdangwal          #+#    #+#             */
/*   Updated: 2025/09/29 13:36:01 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	free_map(t_game *data)
{
	int	i;

	i = 0;
	while (i < data->map->rows + 1)
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
}

void	exit_game(t_game *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->map->sprites[i])
		{
			mlx_destroy_image(data->mlx, data->map->sprites[i]);
			i++;
		}
		else
			break ;
	}
	if (data->mlx && data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	free_map(data);
	exit(0);
}

void	map_loader(t_map *map, t_game *data)
{
	int	i;
	int	j;

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
