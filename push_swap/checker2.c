

#include "push_swap.h"

int	validate_num(long *num, char **arg)
{
	*num = ft_atol(*arg);
	if (!(*num <= INT_MAX && *num >= INT_MIN))
	{
		return (0);
	}
	return (1);
}

void	free_all(int **seen, char ***args)
{
	int i;

	if (*seen != NULL)
		free(*seen);
	i = 0;
	if (*args && *args[i])
	{
		while (args[i])
		{
			free(*args[i]);
			i++;
		}
	}
	free(*args);
	print_error();
}