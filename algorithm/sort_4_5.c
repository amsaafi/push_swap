/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:10:26 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/09 10:34:54 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_4(t_stack **a, t_stack **b, int pos)
{
	if (pos == 0)
		pb(a, b, 1);
	if (pos == 1)
	{
		sa(a, 1);
		pb(a, b, 1);
	}
	if (pos == 2)
	{
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	if (pos == 3)
	{
		rra(a, 1);
		pb(a, b, 1);
	}
	sort_three(a);
	pa(a, b, 1);
}

void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*cur;
	int		pos;
	t_stack	*smallest;

	cur = *a;
	pos = 0;
	smallest = find_smallest(*a);
	while (cur)
	{
		if (smallest == cur)
			break ;
		pos++;
		cur = cur->next;
	}
	sort_4(a, b, pos);
}

static void	sort_5(t_stack **a, t_stack **b, int pos)
{
	if (pos == 0)
		pb(a, b, 1);
	if (pos == 1)
	{
		sa(a, 1);
		pb(a, b, 1);
	}
	if (pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
		pb(a, b, 1);
	}
	if (pos == 3)
	{
		rra(a, 1);
		rra(a, 1);
		pb(a, b, 1);
	}
	if (pos == 4)
	{
		rra(a, 1);
		pb(a, b, 1);
	}
	sort_four(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int		pos;
	t_stack	*smallest;
	t_stack	*cur;

	cur = *a;
	pos = 0;
	smallest = find_smallest(*a);
	while (cur)
	{
		if (smallest == cur)
			break ;
		pos++;
		cur = cur->next;
	}
	sort_5(a, b, pos);
	pa(a, b, 1);
}
