/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:49:34 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:05 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The isalnum() function tests for any character for which isalpha(3)
 * or isdigit(3) is true.  The value of the argument must be representable as
 * an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return int The function returns zero if the character tests false
 * and returns non-zero if the character tests true.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
