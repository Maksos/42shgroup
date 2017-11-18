/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:44:47 by maastie           #+#    #+#             */
/*   Updated: 2017/10/04 17:44:47 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			exec(char **env, char **cmd, char *tmp)
{
	pid_t	father;

	if ((access(tmp, X_OK)) != -1)
	{
		if ((father = fork()) == -1)
			return (-1);
		if (father == 0)
			exit(d->andor = (execve(tmp, cmd, env)));
		else
		{
			waitpid(father, &d->andor, WUNTRACED | WCONTINUED);
			return (d->andor);
		}

	}
	return (1);
}

int		exec_by_p(char **env, char **cmd, char **by, int i)
{
	char	*tmp;

	while (by && by[i])
	{
		tmp = (char *)malloc(sizeof(char) *
			(ft_strlen(by[i]) + ft_strlen(cmd[0]) + 2));
		tmp = ft_strcpy(tmp, by[i]);
		tmp = ft_strcat(tmp, "/");
		tmp = ft_strcat(tmp, cmd[0]);
		if (exec(env, cmd, tmp) == 0)
		{
			ft_strdel(&tmp);
			return (0);
		}
		ft_strdel(&tmp);
		i++;
	}
//	ft_putendl_fd("Error command not found", STDERR_FILENO);
	return (-1);
}

int		check_built_in(char **cmd) // tools
{
	// if >& 
	// while (ft_strin(*cmd, ">&") == 0)
	// 	cmd++;
	if (ft_memcmp(*cmd, "env", 4) == 0)
		return (0);
	else if (ft_memcmp(*cmd, "cd", 3) == 0)
		return (0);
	else if (ft_memcmp(*cmd, "echo", 5) == 0)
		return (0);
	else if (ft_memcmp(*cmd, "setenv", 7) == 0)
		return (0);
	else if (ft_memcmp(*cmd, "unsetenv", 9) == 0)
		return (0);
	// else if (ft_memcmp(*cmd, "export", 2) == 0)
	// 	return (0);
	return (1);
}

int		exec_it(t_red *r, char **env)
{
	// check built in
	// check le path depuis env
	char	**p;

	if (!r->cmd)
		return (-1);
	else if (check_built_in(r->cmd) == 0)
		return (built_in(r->cmd));
	// SHLVLV ./42sh d->tenv;
	// do exec with PATH
	p = ft_strsplit(
	"/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki"
	, ':');
	if (exec_by_p(env, r->cmd, p, 0) == -1)
		d->andor = -1;
	p = ft_free_tab(p);
	return (d->andor);
}