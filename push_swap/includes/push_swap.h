/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:11:34 by sholz             #+#    #+#             */
/*   Updated: 2025/03/22 13:11:36 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>

# include "../ft_printf/include/ft_printf.h"

# define RED "\e[0;31m"
# define YEL "\e[0;33m"

typedef struct s_node
{
	int				value;
	int				sort_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
}					t_stack;

int			*arg_parse(int argc, char **argv, int length);
int			check_digits(int argc, char **argv);
int			check_duplicates(int *numbers, int count);
int			correct_index(int n, int *arr);
int			ft_sqrt(int n);
int			pop_stack(t_stack *stack);
void		free_array(char **arr);
void		check_range(char **s_numbers, int *numbers);
void		insertion_sort(int array[], int n);
void		init_stack(t_stack *stack_a, t_stack *stack_b, int *nb, int c);
void		push_stack(t_stack *stack, int index, int data);
void		shift_elements(int array[], int j, int element);
void		insertion_sort(int array[], int n);
void		sort5(t_stack *stack_a, t_stack *stack_b);
void		sort4(t_stack *stack_a, t_stack *stack_b);
void		sort3(t_stack *stack_a);

void		reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *stack1, t_stack *stack2);
void		rotate_both(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack);
void		swap_both(t_stack *stack1, t_stack *stack2);
void		rotate(t_stack *stack);
void		swap(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_b, t_stack *stack_a);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack_a, t_stack *stack_b);
void		ft_error(char *str, int i);

void		sort(t_stack *stack_a, t_stack *stack_b, int length);
//void		s_insertion_sort(t_stack *stack_a, t_stack *stack_b, int i);
void		big_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void		big_sort2(t_stack *stack_a, t_stack *stack_b, int length);
void		simple_sort(t_stack *stack, int length);
int			is_sorted(t_stack *stack);

int			count_r(t_node *stack, int index);
int			get_min(t_stack *stack);
void		free_stack(t_stack *stack);

#endif // PUSH_SWAP_H
