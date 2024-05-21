/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:10:16 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 10:47:23 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_and_rotate(t_stack **a, t_stack **b, t_stack *cur, int size)
{
	if (cur->pos < size / 2)
	{
		while (*a != cur)
			ra(a, 1);
		pb(a, b, 1);
		rb(b, 1);
	}
	else
	{
		while (*a != cur)
			rra(a, 1);
		pb(a, b, 1);
		rb(b, 1);
	}
	refresh_pos(a);
}

void	reset(int *min, int *max, t_stack **temp, t_stack *top)
{
	(*min)++;
	(*max)++;
	*temp = top;
}

void	push_b(t_stack **a, t_stack **b, t_stack *cur, int size)
{
	if (cur->pos < size / 2)
	{
		while (*a != cur)
			ra(a, 1);
		pb(a, b, 1);
	}
	else
	{
		while (*a != cur)
			rra(a, 1);
		pb(a, b, 1);
	}
	refresh_pos(a);
}

void	push_to_b(t_stack **a, t_stack **b, int size)
{
	int		min;
	int		max;
	t_stack	*temp;

	min = 1;
	max = size / 14;
	temp = *a;
	refresh_pos(a);
	while (temp)
	{
		if (temp->index < min)
		{
			push_and_rotate(a, b, temp, size);
			reset(&min, &max, &temp, *a);
			continue ;
		}
		else if (temp->index >= min && temp->index <= max)
		{
			push_b(a, b, temp, size);
			reset(&min, &max, &temp, *a);
			continue ;
		}
		temp = temp->next;
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	push_to_b(a, b, structlen(*a));
	push_to_a(a, b, structlen(*b));
}
