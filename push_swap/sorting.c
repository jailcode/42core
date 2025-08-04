/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:35:03 by pdangwal          #+#    #+#             */
/*   Updated: 2025/07/15 20:08:53 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

bool	sorted(t_list *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	stack_len(t_list *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	index_stack(t_list *stack)
{
	t_list		*curr;
	t_list		*cmp;
	int			idx;

	curr = stack;
	while (curr)
	{
		idx = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < curr->value)
				idx++;
			cmp = cmp->next;
		}
		curr->index = idx;
		curr = curr->next;
	}
}

void	three_sort(t_list **a)
{
	int		first;
	int		second;
	int		third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	radix_sort(t_list **a, t_list **b)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	size = stack_len(*a);
	max_bits = 0;
	i = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(b, a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
