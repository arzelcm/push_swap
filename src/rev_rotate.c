/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:58:48 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:28:15 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"
#include "stack.h"
#include "operations.h"

void	rev_rotate(t_stack **stack, char id)
{
	t_stack *new_last;

	if (!*stack || !(*stack)->next)
		return ;
	new_last = *stack;
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next->next = *stack;
	*stack = new_last->next;
	new_last->next = NULL;
	if (id != BOTH)
		ft_printf("rr%c\n", id);
}
void	rev_rotate_both(t_stack **a, t_stack **b)
{
	if ((!*a || !(*a)->next) && (!*b || !(*b)->next))
		return ;
	rev_rotate(a, BOTH);
	rev_rotate(b, BOTH);
	ft_printf("rrr\n");
}