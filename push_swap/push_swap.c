/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:21:50 by pdangwal          #+#    #+#             */
/*   Updated: 2025/07/15 20:12:13 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**handle_args(int argc, char **argv, int *use_split)
{
	char	**split;

	split = NULL;
	*use_split = 0;
	if (argc == 2 && argv[1][0])
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (NULL);
		*use_split = 1;
		return (split);
	}
	return (argv + 1);
}

static int	prepare_stack(char **args, t_list **a, t_list **b)
{
	*a = init_a(args);
	if (!*a)
		return (1);
	index_stack(*a);
	if (!sorted(*a))
		run_sort(a, b);
	return (0);
}

static void	cleanup(t_list *a, t_list *b, char **args, int use_split)
{
	free_stack(a);
	free_stack(b);
	if (use_split)
		free_split(args);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**args;
	int		use_split;

	a = NULL;
	b = NULL;
	check_input(argc, argv);
	if (argc == 1)
		return (1);
	args = handle_args(argc, argv, &use_split);
	if (!args)
		return (1);
	if (prepare_stack(args, &a, &b))
	{
		if (use_split)
			free_split(args);
		return (1);
	}
	cleanup(a, b, args, use_split);
	return (0);
}
