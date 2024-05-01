/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:06:29 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 15:13:11 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

void	*safe_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (!res)
		error();
	return (res);
}