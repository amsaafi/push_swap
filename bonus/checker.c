/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:29:53 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/14 12:44:59 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	command_swap(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strncmp(line, "sb\n") == 0)
		sb(b, 0);
	else
		ss(a, b, 0);
}

static void	command_rotate(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strncmp(line, "rb\n") == 0)
		rb(b, 0);
	else
		rr(a, b, 0);
}

static void	command_push(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "pa\n") == 0)
		pa(a, b, 0);
	else
		pb(a, b, 0);
}

static void	command_rev_rotate(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp(line, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strncmp(line, "rrb\n") == 0)
		rrb(b, 0);
	else
		rrr(a, b, 0);
}

void	commands(t_stack **a, t_stack **b, char *line)
{
	if ((ft_strncmp(line, "sa\n") == 0) || (ft_strncmp(line, "sb\n") == 0)
		|| (ft_strncmp(line, "ss\n") == 0))
		command_swap(a, b, line);
	else if ((ft_strncmp(line, "ra\n") == 0) || (ft_strncmp(line, "rb\n") == 0)
		|| (ft_strncmp(line, "rr\n") == 0))
		command_rotate(a, b, line);
	else if ((ft_strncmp(line, "pa\n") == 0) || (ft_strncmp(line, "pb\n") == 0))
		command_push(a, b, line);
	else if ((ft_strncmp(line, "rra\n") == 0) || (ft_strncmp(line,
				"rrb\n") == 0) || (ft_strncmp(line, "rrr\n") == 0))
		command_rev_rotate(a, b, line);
	else
	{
		free_stack(a);
		free(line);
		write(2, "Error\n", 6);
		get_next_line(-99);
	}
}
