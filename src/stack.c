/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 15:51:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "limits.h"
#include "safe_utils.h"
#include "libft.h"
#include "utils.h"

void push_num_stack(t_stack **stack, int num)
{
	t_stack *new;

	new = safe_malloc(sizeof(t_stack));
	new->num = num;
	new->next = *stack;
	*stack = new;
}

void	print_stack(t_stack *stack)
{
	int	i;
	
	ft_printf("--------\n");
	i = 0;
	while (stack)
	{
		ft_printf("%i\n", stack->num);
		stack = stack->next;
	}
	ft_printf("--------\n\n");
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

void	fill_stack(t_stack **stack, int length, char **argv)
{
	int		i;
	long	num;

	i = length - 1;
	while (i >= 0)
	{
		if (!ft_isnum(argv[i]))
			custom_error("Error\nParams must be integers.");
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			custom_error("Error\nNumbers must fit inside an integer.");
		else if (is_duplicated(*stack, num))
			custom_error("Error\nNumbers must not be duplicated.");
		push_num_stack(stack, (int) num);
		i--;
	}
	ft_printf("Filled stack (%p)\n", *stack);
	print_stack(*stack);
}