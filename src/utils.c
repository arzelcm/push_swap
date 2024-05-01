/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:33:54 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 21:49:09 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
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
