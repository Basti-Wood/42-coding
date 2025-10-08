/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:21:12 by sholz             #+#    #+#             */
/*   Updated: 2025/03/15 13:21:14 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	count_r(t_node *stack, int index)
{
	int	count;

	count = 0;
	while (stack && stack->sort_index != index)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	while (stack)
		pop_stack(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	if (is_sorted(stack_a))
		free_stack(stack_a);
	else if (length == 2)
		sa(stack_a);
	else if (length == 3)
		sort3(stack_a);
	else if (length == 4)
		sort4(stack_a, stack_b);
	else if (length == 5)
		sort5(stack_a, stack_b);
	else if (length > 5)
	{
		big_sort1(stack_a, stack_b, length);
		big_sort2(stack_a, stack_b, length);
	}
	else
		ft_error("", 1);
}
