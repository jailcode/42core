/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 12:13:31 by pdangwal          #+#    #+#             */
/*   Updated: 2025/08/04 12:16:23 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!(s[i] <= '9' && s[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	is_duplicate(int *arr, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	validate_args(char **args, int count)
{
	int		i;
	long	num;
	int		*seen;
	int		ret;

	ret = 1;
	seen = malloc(sizeof(int) * count);
	if (!seen)
		print_error();
	i = 0;
	while (i < count)
	{
		if (!is_number(args[i]))
			ret = 0;
		if (!validate_num(&num, &args[i]))
		{
			free(seen);
			print_error();
		}
		if (is_duplicate(seen, i, (int)num))
			ret = 0;
		seen[i] = (int)num;
		i++;
	}
	free(seen);
	return (ret);
}

int	check_input(int argc, char **argv)
{
	char	**args;
	int		count;

	args = NULL;
	if (!argv[1][0])
		return (0);
	if (argc < 2)
		exit(0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args || !args[0])
		{
			free_split(args);
			return (0);
		}
		count = count_args(args);
		if (!validate_args(args, count))
		{
			free_split(args);
			return (0);
		}
	}
	else
	{
		if (!validate_args(&argv[1], argc - 1))
			return (0);
	}
	free_split(args);
	return (1);
}
