/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 11:55:34 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 12:31:40 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n && ++len)
		n /= 10;
	return (len);
}

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int		len;
	char	*str;

	len = get_len(n);
	if (len == 0)
		return (ft_putchar_fd('0', fd));
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (-1);
	str[len] = '\0';
	while (n)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	len = ft_putstr_fd(str, fd);
	return (free(str), len);
}
