/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:51:12 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 16:55:46 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "limits.h"
#include "safe_utils.h"
#include "libft.h"
#include "utils.h"

void	push_num_stack(t_stack **stack, int num)
{
	t_stack	*new;

	new = safe_malloc(sizeof(t_stack));
	new->num = num;
	new->index = -1;
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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	ft_printf("--------\n");
	i = 0;
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("%i", stack_a->num);
			stack_a = stack_a->next;
		}
		ft_printf("  |  ");
		if (stack_b)
		{
			ft_printf("%i", stack_b->num);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("--------\na  |  b\n\n");
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

t_stack	**array_from_stack(t_stack *stack, int len)
{
	int	i;
	t_stack	**arr;

	arr = safe_malloc(sizeof(t_stack) * len);
	i = 0;
	while (stack)
	{
		arr[i++] = stack;
		stack = stack->next;
	}
	return (arr);
}

void	index_nodes(t_stack *stack, int len)
{
	int		i;
	int		j;
	t_stack	**ordered_stack;
	t_stack	*aux;

	ordered_stack = array_from_stack(stack, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (ordered_stack[j + 1]->num < ordered_stack[j]->num)
			{
				aux = ordered_stack[j + 1];
				ordered_stack[j + 1] = ordered_stack[j];
				ordered_stack[j] = aux;
			}
			j++;
		}
		i++;
	}
	while (--i >= 0)
		ordered_stack[i]->index = i + 1;
	free(ordered_stack);
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
	index_nodes(*stack, length);
	ft_printf("Filled stack (%p)\n", *stack);
	print_stack(*stack);
}
