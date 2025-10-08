/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:23 by sholz             #+#    #+#             */
/*   Updated: 2025/03/15 13:21:25 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length);
	while (stack_a->head)
	{
		if (stack_a->head->sort_index <= i)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else if (stack_a->head->sort_index <= i + range)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	big_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length - 1) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->sort_index != length - 1)
				rb(stack_b);
			pa(stack_a, stack_b);
			length--;
		}
		else
		{
			while (stack_b->head->sort_index != length - 1)
				rrb(stack_b);
			pa(stack_a, stack_b);
			length--;
		}
	}
}
