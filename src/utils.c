/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:33:54 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/02 23:07:06 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	custom_error(char *message)
{
	ft_printff(STDERR_FILENO, "%s\n", message);
	exit(EXIT_FAILURE);
}

void	error(void)
{
	perror(PROGRAM_NAME);
	exit(EXIT_FAILURE);
}
