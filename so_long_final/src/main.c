
#include "so_long.h"

void init_sprites(t_game *data)
{
	int i;

	i = 0;
	data->mlx = NULL;
	data->win = NULL;
	while (i < 5)
	{
		data->map->sprites[i] = NULL;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_map map;
	t_game data;

	data.map = &map;
	data.moves = 0;
	map.s = 32;
	if (argc != 2)
		return (1);
	if (!argv[1])
		return (1);
	init_sprites(&data);
	//printf("running: %s\n", argv[1]);
	if (!readmap(&map, &data, argv[1]))
			return(1);
	if (verify_all(&map, &data))
		play_game(&map, &data);
	exit_game(&data);
	return (0);
}