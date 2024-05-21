/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:10:36 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/09 10:10:37 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (biggest->value == (*a)->value)
		ra(a, 1);
	else if ((*a)->next->value == biggest->value)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}
