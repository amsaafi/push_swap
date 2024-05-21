/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:12:04 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 12:39:47 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		exit(1);
	init_stack(ac, av, &a);
	check_doubles(&a);
	if (!is_sorted(a))
	{
		indexing(a);
		if (structlen(a) <= 3)
			sort_three(&a);
		else if (structlen(a) == 4)
			sort_four(&a, &b);
		else if (structlen(a) == 5)
			sort_five(&a, &b);
		else
			sort_all(&a, &b);
	}
	return (free_stack(&a), 0);
}
