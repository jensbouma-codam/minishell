/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 23:21:33 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 12:08:41 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/**
 * @brief Outputs the character ’c’ to the given file
 * descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
