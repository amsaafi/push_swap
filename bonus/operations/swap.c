/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:33 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/12 15:29:26 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!*head || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	sa(t_stack **a, int print)
{
	swap(a);
	if (print == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	swap(b);
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		write(1, "ss\n", 3);
}
