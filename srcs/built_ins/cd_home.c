/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:05:40 by eassouli          #+#    #+#             */
/*   Updated: 2022/04/12 14:32:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_home_plus(char *home, char *new_old, char *arg, char ***env)
{
	char	*path;

	path = ft_strjoin(home, arg + 2);
	if (chdir(path) == false)
		cd_errors(5, arg, path);
	else
		export_join_keyvalue(OLDPWD_KEY, new_old, env);
	if (path)
		free (path);
}

char	*cd_home(char **arg, char ***env)
{
	char	*home;
	char	*new_old;

	home = get_home_dir(*env);
	new_old = get_current_dir();
	if (!home)
		return (arg[1]);
	else if (arg[1] == NULL || ft_strcmp(arg[1], "~") == 0)
	{
		if (chdir(home) == -1)
			cd_errors(0, arg[1], NULL);
		else
			export_join_keyvalue(OLDPWD_KEY, new_old, env);
	}
	else if (arg[1][1] == '/')
		cd_home_plus(home, new_old, arg[1], env);
	else
		cd_errors(0, arg[1], NULL);
	export_join_keyvalue(OLDPWD_KEY, new_old, env);
	free(home);
	return (new_old);
}
