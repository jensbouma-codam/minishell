/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/12 15:55:46 by jensbouma     #+#    #+#                 */
/*   Updated: 2024/01/18 16:09:59 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTER_H
# define PRINTER_H

# include <stdlib.h>
# include "types.h"
# include "stdio.h"
# include "helper/mem.h"

# define RED     "\x1B[31m"
# define GREEN   "\x1B[32m"
# define YELLOW  "\x1B[33m"
# define BLUE    "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN    "\x1B[36m"
# define RESET   "\x1B[0m" 

void	print_list(t_list *list, void (*print_func)(void *, int), int indent);
void	print_token(t_token *token, int indent);
void	print_pipe(t_pipe *pipe, int indent);
void	print_task(t_task *task, int indent);
void	print_redirect(t_redirect *redirect, int indent);
int		print_array(char **arr);
int		print_array_export(char **arr);

#endif