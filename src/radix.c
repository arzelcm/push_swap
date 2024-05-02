/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:03:30 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 21:20:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include "operations.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	bit;
	int	i;

	bit = 1;
	while (!is_sorted_stack(*stack_a))
	{
		i = 0;
		while (i < len && *stack_a)
		{
			if ((*stack_a)->index & bit)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			i++;
		}
		while (*stack_b)
			push(stack_b, stack_a, 'a');
		bit = bit << 1;
	}
}
