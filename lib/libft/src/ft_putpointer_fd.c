/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   put_pointer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 17:07:29 by jbouma        #+#    #+#                 */
/*   Updated: 2023/02/27 11:12:39 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>

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
 * @param p Allocated string
 * @return int number of printed characters.
 */
int	ft_putpointer_fd(void *p, int fd)
{
	int				bits;
	int				value;
	int				count;

	bits = (sizeof((unsigned long)p) << 3);
	count = ft_putstr_fd("0x", fd);
	while (bits)
	{
		value = (((unsigned long)p >> (bits - 4))) & 0xf;
		if (value + '0' != '0' || count > 2)
		{
			if (value < 10)
				count += ft_putchar_fd(value + '0', fd);
			else
				count += ft_putchar_fd(value + 'a' - 10, fd);
		}
		bits -= 4;
	}
	if (count < 3)
		count += ft_putchar_fd('0', fd);
	return (count);
}
