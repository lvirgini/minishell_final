/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_t_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:54:42 by lvirgini          #+#    #+#             */
/*   Updated: 2022/04/12 14:44:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** malloc and create t_redir from this token 
*/

t_redir	*create_redir(int type, char *filename)
{
	t_redir	*redirection;

	redirection = (t_redir *)malloc(sizeof(t_redir));
	if (!redirection)
	{
		perror("malloc add_t_redir()");
		return (NULL);
	}
	redirection->next = NULL;
	redirection->filename = filename;
	redirection->type = type;
	return (redirection);
}
