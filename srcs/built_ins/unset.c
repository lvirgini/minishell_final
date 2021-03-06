/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:26:09 by eassouli          #+#    #+#             */
/*   Updated: 2021/11/29 13:34:54 by eassouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_return_value	g_exit;

static void	unset_error(char *arg, int error)
{
	ft_putstr_fd("unset: ", STDERR_FILENO);
	if (error == NOT_ID)
	{
		ft_putstr_fd("`", STDERR_FILENO);
		ft_putstr_fd(arg, STDERR_FILENO);
		ft_putstr_fd(S_NOT_ID, STDERR_FILENO);
	}
	g_exit.status = 1;
}

void	shift_list(char *arg, char **unset_env)
{
	int	i;
	int	len;

	i = get_env_index(unset_env, arg);
	if (i != -1)
	{
		len = listlen(unset_env);
		free(unset_env[i]);
		list_nmove(unset_env + i, unset_env + i + 1, len - i);
		unset_env[len - 1] = NULL;
	}
}

void	exec_unset(char **arg, char ***env)
{
	int		a;
	int		i;
	char	**unset_env;

	g_exit.status = 0;
	a = 1;
	unset_env = *env;
	while (arg[a])
	{
		i = is_valid_key(arg[a]);
		if (i == 0 || ft_strchr(arg[a], '='))
			unset_error(arg[a], NOT_ID);
		else
			shift_list(arg[a], unset_env);
		a++;
	}
}
