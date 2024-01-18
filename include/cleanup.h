/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/08 14:28:47 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/12/21 12:29:56 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANUP_H
# define CLEANUP_H

# include "types.h"

# include "libft.h"
# include "helper/debug.h"
# include "helper/array.h"

void	free_t_token(void *token);
void	free_t_tasks(void *ptr);
void	semi_clear(t_list **lst);
void	free_t_pipe(void *ptr);

#endif
