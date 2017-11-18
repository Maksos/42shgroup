/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:50:41 by maastie           #+#    #+#             */
/*   Updated: 2017/10/10 14:50:41 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			env_r(char **cmd, int i);

int			print_env(char **env)
{
	int		i;

	i = 0;
	if (!env)
	{
		while (d->env && d->env[i])
			ft_putendl_fd(d->env[i++], d->pdes[1]);		
	}
	else
		while (env && env[i])
			ft_putendl_fd(env[i++], d->pdes[1]);	
	return (0);
}

int			del_by(char **cmd, int i)
{
	int		a;

	if (ft_strchr(cmd[i], '=') != NULL)
		return (-1); // error only variable name is needed
	a = 0;
	while (d->tenv && d->tenv[a])
	{
		if (ft_strncmp(d->tenv[a], cmd[i], ft_strlen(cmd[i]) -1) == 0)
		{
			d->tenv = del_and_ajust_tab(d->tenv, a);
			break ;
		}
		a++;
	}
	return (env_r(cmd, ++i));
}

int			do_opt(char **cmd, int i)
{
	if (!cmd[i][1] || (cmd[i][1] != 'i' && cmd[i][1] != 'u'))
		return (-1); // error bad option
	else if (cmd[i][1] == 'i')
	{
		d->tenv = ft_free_tab(d->tenv);
		d->tenv = NULL;
		return (env_r(cmd, ++i));
	}
	else if (cmd[i][1] == 'u' && !cmd[i + 1])
		return (-1);// error no argument for -u
	else if (cmd[i][1] == 'u' && cmd[i + 1])
		if (del_by(cmd, ++i) == -1) // faire attention au multi del
			return (-1);
	return (env_r(cmd, ++i));
}

int			its_a_built_in(char *cmd)
{
	if (ft_memcmp(cmd, "cd", 2) == 0)
		return (0);
	else if (ft_memcmp(cmd, "setenv", 7) == 0)
		return (0);
	else if (ft_memcmp(cmd, "unsetenv", 9) == 0)
		return (0);	
	else if (ft_memcmp(cmd, "echo", 5) == 0)
		return (0);
	else if (ft_memcmp(cmd, "exit", 5) == 0)
		return (0);
	return (1);
}

int			do_built_in_env(char **cmd, int i)
{
	int		s;
	char	**t;
	pid_t	f;

	s = i;
	while (s > 0)
		ft_strdel(&cmd[--s]);
	s = 0;
	while (cmd[i])
	{
		cmd[s++] = ft_strdup(cmd[i]);
		ft_strdel(&cmd[i++]);
	}
	if ((f = fork()) == -1)
		return (d->andor = -1);
	t = d->env;
	d->env = d->tenv;
	s = 0;
	if (f == 0)
		exit(d->andor = built_in(cmd));
	else
		waitpid(f, &d->andor, WUNTRACED | WCONTINUED);
	d->env = t;
	return (d->andor);
}

char		**check_get_path(char **dst, char *ref)
{
	if (!ref || (ref && ref[0] && ref[0] == '\0'))
	{
		ft_putendl_fd("error No path", STDERR_FILENO);
		return (NULL);
	}
	dst = ft_strsplit(ref, ':');
	ft_strdel(&ref);
	return (dst);
}

char		**get_path_to_exec(char **dst, char **env, char *ref)
{
	int		i;
	int		a;
	char	*t;

	i = 0;
	t = NULL;
	while (env && env[i])
	{
		a = 0;
		if (env[i][a] == ref[a])
		{
			while (env[i][a] && ref[a] && env[i][a] == ref[a])
				a++;
			if (!ref[a])
				return (check_get_path(dst, t = fill_r(d->tenv[i], ref, t)));
			else
				ft_putendl(env[i]);
		}
		i++;
	}
	return (dst = ft_strsplit(
		"/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki"
	, ':'));
}

int			env_exec(char **cmd, int i)
{
	int		s;
	char	**p;

	s = i;
	while (s > 0)
		ft_strdel(&cmd[--s]);
	s = 0;
	while (cmd && cmd[i])
	{
		cmd[s++] = ft_strdup(cmd[i]);
		ft_strdel(&cmd[i++]);
	}
	if ((p = get_path_to_exec(p, d->tenv, "PATH=")) == NULL)
		return (-1);
	d->andor = exec_by_p(d->tenv, cmd, p, 0);
	p = ft_free_tab(p);
	return (d->andor);
}

int			env_r(char **cmd, int i)
{
	while (cmd && cmd[i])
	{
		//if (ft_strchr(cmd[i], ">&") != NULL)
			//
		if (i == 1 && cmd[i][0] && cmd[i][0] == '-')
			return (do_opt(cmd, i));
		else if (ft_strchr(cmd[i], '=') != NULL)
		{
			d->tenv = add_new(d->tenv, cmd[i], 0, 0);
			return (env_r(cmd, ++i));
		}
		else if (its_a_built_in(cmd[i]) == 0)
			return (do_built_in_env(cmd, i));
		else if (ft_memcmp(cmd[i], "env", 3) == 0)
			return (env_r(cmd, ++i));
		else
			return (d->andor = env_exec(cmd, i));
		i++;
	}
	return (print_env(d->tenv));
}

int			ft_env(char **cmd)
{
	if (!cmd[1])
		return (d->andor = print_env(d->env));
	else
	{
		if (d->tenv && d->tenv != NULL)
			d->tenv = ft_free_tab(d->tenv);
		d->tenv = cpy_tab(d->tenv, d->env, 1);
		d->andor = env_r(cmd, 1);
		if (d->tenv && d->tenv != NULL && d->tenv[0] && d->tenv[0] != NULL)
			d->tenv = ft_free_tab(d->tenv);
	}
	return (d->andor);
}