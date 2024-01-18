/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 23:37:38 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 12:47:57 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/**
 * @brief Outputs the integer ’n’ to the given file
 * descriptor.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == INT_MIN)
		count += ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			count += ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n >= 10)
		{
			count += ft_putnbr_fd(n / 10, fd);
		}
		count += ft_putchar_fd(((n % 10) + '0'), fd);
	}
	return (count);
}
