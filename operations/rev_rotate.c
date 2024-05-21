/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:23 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/09 10:11:24 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_stack **stack)
{
	t_stack	*cur;

	if (!(*stack) || !(*stack)->next)
		return ;
	cur = *stack;
	while (cur->next->next)
		cur = cur->next;
	cur->next->next = *stack;
	*stack = cur->next;
	cur->next = NULL;
	cur = NULL;
}

void	rra(t_stack **a, int print)
{
	rev_rotate(a);
	if (print == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	rev_rotate(b);
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print == 1)
		write(1, "rrr\n", 4);
}
