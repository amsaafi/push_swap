/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:28 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/10 08:32:46 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	rotate(t_stack **stack)
{
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	last_node = NULL;
}

void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print == 1)
		write(1, "rr\n", 3);
}
