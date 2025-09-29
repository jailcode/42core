/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:27:31 by pdangwal          #+#    #+#             */
/*   Updated: 2025/09/29 13:27:34 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_map
{
	char	**map;
	void	*sprites[5];
	int		rows;
	int		cols;
	int		p;
	int		c;
	int		e;
	int		s;
	char	*line;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		playerpos[2];
	t_map	*map;
	int		moves;
}			t_game;

char		*ft_strdup(char *s);
int			readmap(t_map *map, t_game *data, char *filename);
int			valid_path(t_map *map, int px, int py);
int			verify_all(t_map *map, t_game *data);
void		play_game(t_map *map, t_game *data);
int			key_hook(int keycode, t_game *data);
void		move_player(t_map *map, t_game *data, int x, int y);
int			game_update(t_game *data);
void		map_loader(t_map *map, t_game *data);
void		exit_game(t_game *data);
void		print_int(int n);
int			close_win(t_game *data);
void		map_loader(t_map *map, t_game *data);
void		render_tile(t_map *map, t_game *data, int x, int y);