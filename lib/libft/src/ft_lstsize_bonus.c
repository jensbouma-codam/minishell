/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:01:57 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 14:33:44 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in a list.
 * 
 * @param lst The beginning of the list.
 * @return int The length of the list
 */
int	ft_lstsize(t_list *lst)
{
	int		len;

	len = 0;
	while (lst && ++len)
		lst = lst->next;
	return (len);
}
