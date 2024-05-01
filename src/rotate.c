/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:18:19 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:51:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"
#include "operations.h"

void	rotate(t_stack **stack, char id)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = *stack;
	*stack = (*stack)->next;
	last->next->next = NULL;
	if (id != BOTH)
		ft_printf("r%c\n", id);
}

void	rotate_both(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	rotate(a, BOTH);
	rotate(b, BOTH);
	ft_printf("rr\n");
}
