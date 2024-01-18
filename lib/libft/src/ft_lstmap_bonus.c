/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jbouma <jbouma@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 17:28:51 by jbouma        #+#    #+#                 */
/*   Updated: 2022/11/21 15:37:53 by jbouma        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function
 * ’f’ on the content of each node.  Creates a new
 * list resulting of the successive applications of
 * the function ’f’.  The ’del’ function is used to
 * delete the content of a node if needed.
 * 
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete 
 * the content of a node if needed.
 * @return t_list* The new list. NULL if the allocation fails.
 */
static t_list	*set_zero(void *buf, void (*del)(void *))
{
	del(buf);
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;
	void	*buf;

	if (!lst || !f || !del)
		return (0);
	buf = f(lst->content);
	newlst = ft_lstnew(buf);
	if (!newlst)
		return (set_zero(buf, del));
	lst = lst->next;
	while (lst)
	{	
		buf = f(lst->content);
		node = ft_lstnew(buf);
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (set_zero(buf, del));
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}
