/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:51 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/09 10:11:52 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	*stack_to_arr(t_stack *stack)
{
	int	size;
	int	*arr;
	int	i;

	size = structlen(stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

int	*sort_arr(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!arr)
		return (NULL);
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	indexing(t_stack *stack)
{
	int		size;
	int		*arr;
	int		i;
	t_stack	*current;

	size = structlen(stack);
	arr = stack_to_arr(stack);
	arr = sort_arr(arr, size);
	current = stack;
	if (!arr)
		return ;
	while (current)
	{
		i = 0;
		while (i++ < size)
		{
			if (arr[i] == current->value)
			{
				current->index = i;
				break ;
			}
		}
		current = current->next;
	}
	free(arr);
}
