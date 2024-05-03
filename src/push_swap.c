/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:29:03 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/03 13:59:16 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "operations.h"
#include "radix.h"

void	sort_three(t_stack **a)
{
	if (((*a)->num < (*a)->next->num && (*a)->num < (*a)->next->next->num)
		|| ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num
			&& (*a)->next->num > (*a)->next->next->num))
		swap(a, 'a');
	if ((*a)->num > (*a)->next->num && (*a)->next->num < (*a)->next->next->num
		&& (*a)->num < (*a)->next->next->num)
		swap(a, 'a');
	else if ((*a)->num < (*a)->next->num
		&& (*a)->next->num > (*a)->next->next->num)
		rev_rotate(a, 'a');
	else if ((*a)->num > (*a)->next->num && (*a)->num > (*a)->next->next->num
		&& (*a)->num > (*a)->next->next->num)
		rotate(a, 'a');
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;
	int	actual;

	actual = 0;
	min = get_min_stack_num(*a);
	if ((*a)->num == min)
		actual = 0;
	else if ((*a)->next->num == min)
		actual = 1;
	else if ((*a)->next->next->num == min)
		actual = 2;
	else
		rev_rotate(a, 'a');
	while (actual-- > 0)
		rotate(a, 'a');
	push(a, b, 'b');
	sort_three(a);
	push(b, a, 'a');
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	actual;

	actual = 0;
	min = get_min_stack_num(*a);
	if ((*a)->num == min)
		actual = 0;
	else if ((*a)->next->num == min)
		actual = 1;
	else if ((*a)->next->next->num == min)
		actual = 2;
	else if ((*a)->next->next->next->num == min)
		actual = 3;
	else
		rev_rotate(a, 'a');
	while (actual-- > 0)
		rotate(a, 'a');
	push(a, b, 'b');
	sort_four(a, b);
	push(b, a, 'a');
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	stack_a = NULL;
	stack_b = NULL;
	fill_stack(&stack_a, argc - 1, argv + 1);
	if (is_sorted_stack(stack_a))
		exit(EXIT_SUCCESS);
	else if (argc - 1 == 2)
		swap(&stack_a, 'a');
	else if (argc - 1 == 3)
		sort_three(&stack_a);
	else if (argc - 1 == 4)
		sort_four(&stack_a, &stack_b);
	else if (argc - 1 == 5)
		sort_five(&stack_a, &stack_b);
	else
		sort_stack_radix(&stack_a, &stack_b, argc - 1);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
