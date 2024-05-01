/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:33:54 by arcanava          #+#    #+#             */
/*   Updated: 2024/05/01 14:38:24 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

void	custom_error(char *message)
{
	ft_printff(STDERR_FILENO, "%s\n", message);
	ft_printf("\033[?25h");
	exit(EXIT_FAILURE);
}