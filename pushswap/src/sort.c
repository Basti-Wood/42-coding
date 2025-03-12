#include "../includes/push_swap.h"

int	is_rot_sort(t_stack *stack, int min_s_index)
{
	int	a;
	int	b;
	int	c;

	(void)min_s_index;
	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack, int length)
{
	int		min_s_index;
	int		r;

	if (is_sorted(stack))
		return ;
	min_s_index = get_min(stack);
	r = count_r(stack->head, min_s_index);
	if (is_rot_sort(stack, min_s_index))
	{
		if (r < length - r)
			ra(stack);
		else
			rra(stack);
	}
	else
	{
		sa(stack);
		if (is_sorted(stack))
			return ;
		if (r < length - r)
			ra(stack);
		else
			rra(stack);
	}
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length);
	while (stack_a->head)
	{
		if (stack_a->head->s_index <= i)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if (stack_a->head->s_index <= i + range)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length + 1) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->s_index != length - 1)
				rb(stack_b);
			pa(stack_a, stack_b);
			length--;
		}
		else
		{
			while (stack_b->head->s_index != length - 1)
				rrb(stack_b);
			pa(stack_a, stack_b);
			length--;
		}
	}
}
