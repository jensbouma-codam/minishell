/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/21 11:54:09 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:32:54 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

/**
 * @brief  The atoi() function converts the initial portion of 
 * the string pointed to by str to int representation.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi(char *str)
{
	int				min;
	unsigned long	calc;

	min = 1;
	calc = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min = -min;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		calc = calc * 10 + (*str - '0');
		str++;
	}
	return (calc * min);
}
