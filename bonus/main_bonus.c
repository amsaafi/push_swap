/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:04:29 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 11:02:13 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	checker(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && !*b)
	{
		free_stack(a);
		write(1, "OK\n", 3);
	}
	else
	{
		free_stack(a);
		free_stack(b);
		write(2, "KO\n", 3);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		exit(1);
	init_stack(ac, av, &a);
	check_doubles(&a);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		commands(&a, &b, line);
		free(line);
	}
	checker(&a, &b);
	return (0);
}
