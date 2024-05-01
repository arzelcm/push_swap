/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:41:07 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 20:14:39 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void	push(t_stack **src, t_stack **dst, char id)
{
	t_stack *target;

	target = *src;
	*src = (*src)->next;
	target->next = *dst;
	*dst = target;
	ft_printf("p%c\n", id);
}