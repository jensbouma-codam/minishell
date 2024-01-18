/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 14:03:43 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 11:55:02 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "helper/int.h"

bool	int_find(int token, int *list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		if (list[i] == token)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
