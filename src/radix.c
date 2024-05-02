/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:03:30 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 20:08:57 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "operations.h"

int	get_min_stack_num(t_stack *stack)
{
	int	min;

	min = stack->num;
	while (stack)
	{
		if (min > stack->num)
			min = stack->num;
		stack = stack->next;
	}
	return (min);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	i;
	int	j;

	i = 1;
	while (!is_sorted_stack(*stack_a))
	{
		j = 0;
		while (j < len && *stack_a)
		{
			if ((*stack_a)->index & i)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		i = i << 1;
	}
}
