
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_map map;
	t_game data;

	data.map = &map;
	map.s = 32;
	if (argc != 2)
		return (1);
	if (!argv[1])
		return (1);
	printf("%s", argv[1]);
	if (!readmap(&map, argv[1]))
			return(1);
	if (verify_all(&map, &data))
		play_game(&map, &data);
	exit_game(&data);
	return (0);
}