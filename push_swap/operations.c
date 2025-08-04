/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:43:00 by pdangwal          #+#    #+#             */
/*   Updated: 2025/07/15 19:56:47 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_list **stack, t_list *node)
{
	node->next = *stack;
	*stack = node;
}

void	pa(t_list **a, t_list **b)
{
	t_list		*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	push_top(a, tmp);
	write(1, "pa\n", 3);
}

void	ra(t_list **a)
{
	t_list		*first;
	t_list		*last;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

void	sa(t_list **a)
{
	t_list		*first;
	t_list		*second;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

void	rra(t_list **a)
{
	t_list		*prev;
	t_list		*last;

	prev = NULL;
	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}
