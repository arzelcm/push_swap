/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:01:14 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 20:58:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include "stack.h"

void	push_num_stack(t_stack **stack, int num);

int		is_duplicated(t_stack *stack, int num);

#endif