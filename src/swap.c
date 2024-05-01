/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:18:40 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:49:21 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operations.h"
#include "libft.h"
#include "swap.h"

void	swap(t_stack **stack, char id)
{
	t_stack	*old;

	if (!*stack || !(*stack)->next)
		return ;
	old = *stack;
	*stack = (*stack)->next;
	old->next = (*stack)->next;
	(*stack)->next = old;
	if (id != BOTH)
		ft_printf("s%c\n", id);
}

void	swap_both(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	swap(a, BOTH);
	swap(b, BOTH);
	ft_printf("ss\n");
}
