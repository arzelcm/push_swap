/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:29:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 19:00:53 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "stack.h"
#include "operations.h"
#include "radix.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argc - 1, argv + 1);
	if (is_sorted_stack(stack_a))
	{
		ft_printf("sorted!\n");
		return (EXIT_SUCCESS);
	}
	else
		sort_stack(&stack_a, &stack_b, argc - 1);
	return (EXIT_SUCCESS);
}
