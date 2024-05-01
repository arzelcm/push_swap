/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:29:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:53:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "stack.h"
#include "operations.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;

	fill_stack(&stack_a, argc - 1, argv + 1);
	
	swap(&stack_a, 'a');
	print_stacks(stack_a, stack_b);

	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	push(&stack_a, &stack_b, 'b');
	print_stacks(stack_a, stack_b);

	rotate_both(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);

	rev_rotate_both(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);

	swap(&stack_a, 'a');
	print_stacks(stack_a, stack_b);

	push(&stack_b, &stack_a, 'a');
	push(&stack_b, &stack_a, 'a');
	push(&stack_b, &stack_a, 'a');
	print_stacks(stack_a, stack_b);

	return (0);
}
