/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:45:16 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/21 16:40:11 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_to_a(t_stack **a, t_stack **b, int size)
{
	t_stack	*cur;

	cur = *b;
	refresh_pos(b);
	while (cur)
	{
		if (cur == find_biggest(*b))
		{
			if (cur->pos < size / 2)
			{
				while (*b != cur)
					rb(b, 1);
				pa(a, b, 1);
				refresh_pos(b);
			}
			else
			{
				while (*b != cur)
					rrb(b, 1);
				pa(a, b, 1);
				refresh_pos(b);
			}
			size = structlen(*b);
		}
		cur = cur->next;
	}
}
