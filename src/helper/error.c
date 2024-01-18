/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 13:57:08 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/16 09:26:29 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/error.h"

/**
 * @brief Prints the errno message to STDERR_FILENO.
 * @param str error message
 * @return int errno or EXIT_FAILURE
 */
int	error(char *str)
{
	if (errno != 0)
	{
		if (str)
			perror(str);
		return (errno);
	}
	ft_putendl_fd(str, STDERR_FILENO);
	return (EXIT_FAILURE);
}
