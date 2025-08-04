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
	int	len = 0;

	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

// Assigns sorted index to each node based on values
void	index_stack(t_list *stack)
{
	t_list *curr = stack;
	t_list *cmp;
	int idx;

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
	int first;
	int second;
	int third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;

	if (first > second && second < third && first < third)
		sa(a); // Case: 2 1 3 -> swap top two
	else if (first > second && second > third)
	{
		sa(a); // 3 2 1 -> swap first two to get 2 3 1
		rra(a); // then reverse rotate to 1 2 3
	}
	else if (first > second && second < third && first > third)
		ra(a); // 2 1 3 -> rotate to 1 3 2
	else if (first < second && second > third && first < third)
	{
		sa(a); // 1 3 2 -> swap to 3 1 2
		ra(a); // rotate to 1 2 3
	}
	else if (first < second && second > third && first > third)
		rra(a); // 2 3 1 -> reverse rotate to 1 2 3
}

void	radix_sort(t_list **a, t_list **b)
{
	int	size = stack_len(*a);
	int	max_bits = 0;
	int	i = 0;
	int	j;

	// Calculate number of bits needed to represent max index
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

