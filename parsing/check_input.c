/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:11:39 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 11:12:13 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_num(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = data;
	new_node->next = *stack;
	*stack = new_node;
}

int	is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0' || str == NULL)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] > '9' || str[i] < '0')
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

void	check_doubles(t_stack **a)
{
	t_stack	*cur;
	t_stack	*tmp;

	cur = *a;
	while (cur != NULL)
	{
		tmp = cur->next;
		while (tmp != NULL)
		{
			if (cur->value == tmp->value)
			{
				write(2, "Error\n", 6);
				free_stack(a);
				exit(1);
			}
			tmp = tmp->next;
		}
		cur = cur->next;
	}
}

void	check_numeric(char **arr_split, t_stack **a, int *index)
{
	long	num;
	int		j;

	j = *index;
	if (is_numeric(arr_split[j]))
	{
		num = ft_atol(arr_split[j]);
		if (num <= INT_MAX && num >= INT_MIN)
			push_num(a, num);
		else
		{
			free_all(a, arr_split);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	else
	{
		free_all(a, arr_split);
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	init_stack(int ac, char **av, t_stack **a)
{
	int		i;
	int		j;
	char	**arr_split;

	j = 0;
	i = ac;
	i--;
	while (i > 0)
	{
		arr_split = ft_split(av[i], ' ');
		if (is_fspace(av[i]))
			ft_exit(a, arr_split);
		j = len_arrsplit(arr_split);
		j--;
		while (j >= 0)
		{
			check_numeric(arr_split, a, &j);
			j--;
		}
		free_arr(arr_split);
		i--;
	}
}
