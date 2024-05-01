/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:17:43 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 20:34:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "stack.h"

void	rotate(t_stack **stack, char id);

void	rotate_both(t_stack **a, t_stack **b);

#endif