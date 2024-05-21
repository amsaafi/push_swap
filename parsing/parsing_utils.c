/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:57 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 10:31:52 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	len_arrsplit(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	structlen(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	is_fspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*cur;

	cur = stack;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
		{
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

void	ft_exit(t_stack **stack, char **arr_split)
{
	free_all(stack, arr_split);
	write(2, "Error\n", 6);
	exit(1);
}
