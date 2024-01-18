/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isprint.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 14:50:20 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:15 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The isprint() function tests for any printing character,
 * including space (` ').  The value of the argument must be representable as
 * an unsigned char or the value of EOF.
 * 
 * @param c 
 * @return int The isprint() function returns zero if the character tests false
 * and returns non-zero if the character tests true.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
