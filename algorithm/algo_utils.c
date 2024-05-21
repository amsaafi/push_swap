/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:10:07 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 10:46:21 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_biggest(t_stack *src)
{
	t_stack	*biggest;

	biggest = src;
	while (src != NULL)
	{
		if (biggest->value < src->value)
			biggest = src;
		src = src->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *src)
{
	t_stack	*smallest;

	smallest = src;
	while (src != NULL)
	{
		if (smallest->value > src->value)
			smallest = src;
		src = src->next;
	}
	return (smallest);
}

void	refresh_pos(t_stack **stack)
{
	t_stack	*cur;
	int		pos;

	cur = *stack;
	pos = 0;
	while (cur)
	{
		cur->pos = pos;
		pos++;
		cur = cur->next;
	}
}
