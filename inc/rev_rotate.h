/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:58:57 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:28:00 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ROTATE_H
# define REV_ROTATE_H

# include "stack.h"

void	rev_rotate(t_stack **stack, char id);

void	rev_rotate_both(t_stack **a, t_stack **b);

#endif