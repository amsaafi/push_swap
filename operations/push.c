/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:14 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/09 10:11:15 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **stack, int value, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = *stack;
	new_node->index = index;
	*stack = new_node;
}

static void	ft_del(t_stack **stack)
{
	t_stack	*cur;

	if (!*stack)
		return ;
	cur = *stack;
	*stack = (*stack)->next;
	free(cur);
	cur = NULL;
}

static void	push_from_stack(t_stack **src, t_stack **dest)
{
	if (*src)
	{
		push(dest, (*src)->value, (*src)->index);
		ft_del(src);
	}
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push_from_stack(b, a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push_from_stack(a, b);
	if (print)
		write(1, "pb\n", 3);
}
