

#include "../includes/push_swap.h"

int	get_min(t_stack *stack)
{
	t_node	*current;
	int		min_index;

	current = stack->head;
	min_index = current->s_index;
	while (current->next)
	{
		current = current->next;
		if (current->s_index < min_index)
			min_index = current->s_index;
	}
	return (min_index);
}

int	count_r(t_node *stack, int index)
{
	int	count;

	count = 0;
	while (stack && stack->s_index != index)
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
		if (tmp->data > tmp->next->data)
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
	{
		//free(numbers);
		free_stack(stack_a);
		display_error("", 1);
	}
	else if (length == 2)
		sa(stack_a);
	else if (length == 3)
		simple_sort(stack_a, length);
	else if (length > 3)
	{
		k_sort1(stack_a, stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		display_error("", 1);
}
