/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:40:55 by pdangwal          #+#    #+#             */
/*   Updated: 2025/07/15 20:09:09 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_list{

	int	value;
	int	index;
	struct s_list *prev;
	struct s_list* next;
} t_list;

void	radix_sort(t_list **a, t_list **b);
char	**ft_split(char const *s, char c);
int	ft_atol(const char *str);
bool	sorted(t_list *a);
void	three_sort(t_list **a);
int	stack_len(t_list *stack);
void	index_stack(t_list *stack);
void	pb(t_list **b, t_list **a);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	sa(t_list **a);
void	rra(t_list **a);
//int	ft_numstrings(char const *s, char c);
