/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 22:52:52 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 16:00:30 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a string
 * representing the integer received as an argument.
 * Negative numbers must be handled.
 * 
 * @param n	integer input 
 * @return char*  output in characters
 */
static int	get_len(int n)
{
	int	len;

	len = 0;
	while (n && ++len)
		n /= 10;
	return (len);
}

static char	*calculate_all(int i, int n, long int longn, char *output)
{
	while (i--)
	{
		if (n < 0 && !i)
			output[i] = '-';
		else
			output[i] = ((int)(longn % 10) + '0');
		longn /= 10;
	}
	return ((char *)output);
}

char	*ft_itoa(int n)
{
	long int	longn;
	char		*output;
	int			len;
	int			i;

	if (!n)
	{
		output = ft_calloc(2, sizeof(char));
		if (!output)
			return (0);
		output[0] = '0';
		return ((char *)output);
	}
	longn = n;
	len = get_len(longn);
	i = len;
	if (longn < 0 && i++)
		longn *= -1;
	output = ft_calloc(i + 1, sizeof(char));
	if (!output)
		return (0);
	return (calculate_all(i, n, longn, output));
}
