/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthex_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 17:07:29 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/22 12:47:37 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/**
 * @brief Prints out a pointer adres in hexdecimal
 * 1st comvert to unsigned long. 
 * On a 64 bit systems the pointer is 8 bytes long, on a 32bit system 4 bytes.
 * Shift the length << 3 to get 64 or 32.
 * While there a bit left the while continues.
 * Each run shift 4 bits from end to begin as a hexadecimal is 4 bits.
 * The result is passed to the AND operator for a base 16 conversion to get a
 * number from 0 - 15.
 * To get the char value we add '0' to all the values from 0 > 9 and
 * add a 'a' - 10 to everything higer than 9.
 *
 * @param n long int
 * @param type 'x' or 'X'
 * @return int number of printed characters.
 */
int	ft_puthex_fd(int n, char type, int fd)
{
	int				bits;
	int				value;
	int				count;

	bits = (sizeof(n) << 3);
	count = 0;
	while (bits)
	{
		value = ((n >> (bits - 4))) & 0xf;
		if (value + '0' != '0' || count)
		{
			if (value < 10)
				count += ft_putchar_fd(value + '0', fd);
			else
				count += ft_putchar_fd(value + type - 33, fd);
		}
		bits -= 4;
	}
	if (count < 1)
		count += ft_putchar_fd('0', fd);
	return (count);
}
