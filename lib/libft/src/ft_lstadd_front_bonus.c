/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 15:27:43 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:38:38 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * 
 * @param lst The address of a pointer to the first link of
 * a list.
 * @param new The address of a pointer to the node to be
 * added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
