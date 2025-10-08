/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:54:24 by sholz             #+#    #+#             */
/*   Updated: 2025/03/24 18:54:25 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort3(t_stack *stack_a)
{
	t_node	*top;
	int		a;
	int		b;
	int		c;

	top = stack_a->head;
	a = top->sort_index;
	b = top->next->sort_index;
	c = top->next->next->sort_index;
	if (a > b && a > c)
	{
		ra(stack_a);
		if (b > c)
			sa(stack_a);
	}
	else if (b > a && b > c)
	{
		rra(stack_a);
		if (a < c)
			sa(stack_a);
	}
	else if (a > b)
		sa(stack_a);
}

void	sort4(t_stack *stack_a, t_stack *stack_b)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack_a->head;
	while (current && current->sort_index != 0)
	{
		current = current->next;
		pos++;
	}
	if (pos <= stack_a->size / 2)
	{
		while (pos--)
			ra(stack_a);
	}
	else
	{
		while (pos++ < stack_a->size)
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

static void	sort52(t_stack *stack_a, t_stack *stack_b)
{
	int		pos;
	t_node	*current;

	pos = 0;
	current = stack_a->head;
	while (current && current->sort_index != 1)
	{
		current = current->next;
		pos++;
	}
	if (pos <= stack_a->size / 2)
	{
		while (pos--)
			ra(stack_a);
	}
	else
	{
		while (pos++ < stack_a->size)
			rra(stack_a);
	}
	pb(stack_b, stack_a);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort5(t_stack *a, t_stack *b)
{
	int		p;
	t_node	*c;

	p = 0;
	c = a->head;
	while (c && c->sort_index != 0)
	{
		c = c->next;
		p++;
	}
	if (p <= a->size / 2)
		while (p--)
			ra(a);
	else
		while (p++ < a->size)
			rra(a);
	pb(b, a);
	sort52(a, b);
	pa(a, b);
}
