/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_II.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:45:32 by pdangwal          #+#    #+#             */
/*   Updated: 2025/08/04 16:45:36 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(long value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

t_list	*init_a(char **argv)
{
	t_list	*head;
	t_list	*curr;
	t_list	*node;
	int		i;

	head = NULL;
	curr = NULL;
	i = 0;
	while (argv[i])
	{
		node = new_node(atol(argv[i]));
		if (!node)
			return (NULL);
		if (!head)
			head = node;
		else
			curr->next = node;
		curr = node;
		i++;
	}
	return (head);
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	run_sort(t_list **a, t_list **b)
{
	int	len;

	len = stack_len(*a);
	if (len == 1)
		return ;
	if (len == 2)
		sa(a);
	else if (len == 3)
		three_sort(a);
	else
		radix_sort(a, b);
}
