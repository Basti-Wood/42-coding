/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:43:24 by asioud            #+#    #+#             */
/*   Updated: 2023/01/21 06:40:35 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
}

void sa(t_stack *stack)
{
  swap(stack);
  printf("sa\n");
}
void sb(t_stack *stack)
{
  swap(stack);
  printf("sb\n");
}
void ss(t_stack *stack_a, t_stack *stack_b)
{
  swap(stack_a);
  swap(stack_b);
  printf("ss\n");
}

void	push(t_stack *stack1, t_stack *stack2)
{
	int	index;

	if (stack2->head == NULL)
		return ;
	index = stack2->head->s_index;
	push_stack(stack1, index, pop_stack(stack2));
}
void	pa(t_stack *stack_a, t_stack *stack_b)
{
  push(stack_a, stack_b);
  printf("pa\n");
}
void	pb(t_stack *stack_b, t_stack *stack_a)
{
  push(stack_b, stack_a);
  printf("pb\n");
}

void	rotate(t_stack *stack)
{
	t_node	*tmp;
	t_node	*current;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	current = stack->head;
	while (current->next != NULL)
		current = current->next;
	current->next = tmp;
	tmp->next = NULL;
}
void	ra(t_stack *stack)
{
 rotate(stack);
 printf("ra\n");
}
void	rb(t_stack *stack)
{
 rotate(stack);
 printf("rb\n");
}
void	rr(t_stack *stack_a, t_stack *stack_b)
{
 rotate(stack_a);
 rotate(stack_b);
 printf("rr\n");
}


void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*tmp;

	if (!stack->head || !stack->head->next || !stack)
		return ;
	current = stack->head;
	while (current->next->next != NULL)
		current = current->next;
	tmp = current->next;
	current->next = NULL;
	tmp->next = stack->head;
	stack->head = tmp;
}

void	rra(t_stack *stack)
{
 reverse_rotate(stack);
 printf("rra\n");
}
void	rrb(t_stack *stack)
{
 reverse_rotate(stack);
 printf("rrb\n");
}
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
 reverse_rotate(stack_a);
 reverse_rotate(stack_b);
 printf("rrr\n");
}
