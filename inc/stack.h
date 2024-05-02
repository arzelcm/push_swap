/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:49:25 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 20:59:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	int				num;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	push_num_stack(t_stack **stack, int num);

void	fill_stack(t_stack **stack_a, int length, char **argv);

int		is_sorted_stack(t_stack *stack);

#endif