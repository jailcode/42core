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

static t_list	*new_node(long value)
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

t_list	*init_a(char *argv[])
{
    t_list	*head;
    t_list	*curr;
    int		i;

    head = NULL;
    curr = NULL;
    i = 0;
    while (argv[i])
    {
        t_list *node = new_node(atol(argv[i]));
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

    i = 0;
    if (!split)
        return ;
    while (split[i])
        free(split[i++]);
    free(split);
}

static void	run_sort(t_list **a, t_list **b)
{
    int	len;

    len = stack_len(*a);
    if (len == 1)
        return ;
    else if (len == 2)
        sa(a);
    else if (len == 3)
        three_sort(a);
    else
        radix_sort(a, b);
}

int	main(int argc, char *argv[])
{
    t_list	*a;
    t_list	*b;
    char	**split;
    int		use_split;

    a = NULL;
    b = NULL;
    split = NULL;
    use_split = 0;
    if (argc == 1)
        return (1);
    if (argc == 2 && argv[1][0])
    {
        split = ft_split(argv[1], ' ');
        argv = split;
        use_split = 1;
    }
    else
        argv++;
    a = init_a(argv);
    index_stack(a);
    if (!sorted(a))
        run_sort(&a, &b);
    free_stack(a);
    free_stack(b);
    if (use_split)
        free_split(split);
    return (0);
}
