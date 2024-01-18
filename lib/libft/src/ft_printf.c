/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/03 18:36:35 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 13:55:37 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	process_int(char c, int n)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd(n, STDOUT_FILENO));
	else if (c == 'u')
		return (ft_putunsigned_fd(n, STDOUT_FILENO));
	else if (c == 'c')
		return (ft_putchar_fd(n, STDOUT_FILENO));
	else if (c == 'x' || c == 'X')
		return (ft_puthex_fd(n, c, STDOUT_FILENO));
	return (0);
}

int	process_char(char c, char *str)
{
	if (c == 's')
		return (ft_putstr_fd(str, STDOUT_FILENO));
	else if (c == 'p')
		return (ft_putpointer_fd(str, STDOUT_FILENO));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		length;
	int		return_length;

	length = 0;
	va_start(list, s);
	while (*s)
	{
		if (*s == '%' && *s++ && *s != '%')
		{
			if (*s == 'c' || *s == 'd' || *s == 'i'
				|| *s == 'u' || *s == 'x' || *s == 'X')
				return_length = process_int(*s, va_arg(list, int));
			else if (*s == 's' || *s == 'p')
				return_length = process_char(*s, va_arg(list, char *));
		}
		else
			return_length = ft_putchar_fd(*s, STDOUT_FILENO);
		if (write(STDOUT_FILENO, "", 0) == -1 || return_length == -1)
			return (-1);
		length += return_length;
		s++;
	}
	return (va_end(list), length);
}
