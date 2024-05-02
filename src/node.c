/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:00:06 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 17:02:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "safe_utils.h"

void	push_num_stack(t_stack **stack, int num)
{
	t_stack	*new;

	new = safe_malloc(sizeof(t_stack));
	new->num = num;
	new->index = -1;
	new->next = *stack;
	*stack = new;
}

int	is_duplicated(t_stack *stack, int num)
{
	int	duplicated;

	duplicated = 0;
	while (stack && !duplicated)
	{
		duplicated = stack->num == num;
		stack = stack->next;
	}
	return (duplicated);
}