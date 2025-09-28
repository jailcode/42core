

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"
#include <string.h>
#include "../minilibx-linux/mlx.h"


typedef struct s_map
{
	char	**map;
	void	*sprites[5];
	int	rows;
	int	cols;
	int	p;
	int	c;
	int	e;
	int	s;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int	playerpos[2];
	t_map *map;
}	t_game;

char    *ft_strdup(char *s);
int	readmap(t_map *map, char *filename);
int valid_path(t_map *map, int px, int py);
int verify_all(t_map *map, t_game *data);
void	play_game(t_map *map, t_game *data);
int key_hook(int keycode, t_game *data);
void    player_pos(t_map *map, t_game *data, int x, int y);
int game_update(t_game *data);
void map_loader(t_map *map, t_game *data);
void exit_game(t_game *data);
void free_gnl_buffers(void);