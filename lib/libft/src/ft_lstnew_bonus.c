/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 14:51:23 by jbouma        #+#    #+#                 */
/*   Updated: 2023/04/13 15:41:35 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’.
 * The variable * ’next’ is initialized to NULL.
 * 
 * @param content The content to create the node with.
 * @return t_list* The new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)ft_calloc(1, sizeof(*node));
	if (!node)
		return (0);
	node->content = content;
	node->next = 0;
	return (node);
}
