/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:12:11 by samsaafi          #+#    #+#             */
/*   Updated: 2024/05/13 10:52:28 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}					t_stack;

/*****************operations*************************/
void				pa(t_stack **a, t_stack **b, int print);
void				pb(t_stack **a, t_stack **b, int print);
void				sa(t_stack **a, int print);
void				sb(t_stack **b, int print);
void				ss(t_stack **a, t_stack **b, int print);
void				rra(t_stack **a, int print);
void				rrb(t_stack **b, int print);
void				rrr(t_stack **a, t_stack **b, int print);
void				ra(t_stack **a, int print);
void				rb(t_stack **b, int print);
void				rr(t_stack **a, t_stack **b, int print);

/*****************includes****************************/
char				**ft_split(char const *s, char c);
t_stack				*ft_lstlast(t_stack *lst);
long				ft_atol(char *str);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);

/******************parsing****************************/
void				free_stack(t_stack **stack);
void				free_arr(char **str_arr);
void				free_all(t_stack **a, char **str_arr);
void				push_num(t_stack **stack, int data);
int					is_numeric(char *str);
void				check_doubles(t_stack **a);
void				init_stack(int ac, char **av, t_stack **a);
size_t				len_arrsplit(char **str);
int					structlen(t_stack *stack);
void				indexing(t_stack *stack);
int					is_sorted(t_stack *stack);
int					is_fspace(char *str);
void				ft_exit(t_stack **stack, char **arr_split);

/*******************algorithm**************************/
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				sort_all(t_stack **a, t_stack **b);
void				push_to_a(t_stack **a, t_stack **b, int size);

// algo utils
t_stack				*find_biggest(t_stack *src);
t_stack				*find_smallest(t_stack *src);
void				refresh_pos(t_stack **stack);

#endif
