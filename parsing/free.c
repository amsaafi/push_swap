/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:45 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 10:41:55 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
	tmp = NULL;
}

void	free_arr(char **str_arr)
{
	int	i;

	i = 0;
	if (!str_arr)
		return ;
	while (str_arr[i])
	{
		free(str_arr[i]);
		str_arr[i] = NULL;
		i++;
	}
	free(str_arr);
}

void	free_all(t_stack **a, char **str_arr)
{
	free_stack(a);
	free_arr(str_arr);
}
