/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:25:31 by maastie           #+#    #+#             */
/*   Updated: 2017/10/09 18:25:31 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			ft_echo(char **cmd)
{
	int		l;
	int		i;

	l = 0;
	if (cmd && cmd[1])
	{
		if (ft_memcmp(cmd[1], "-n", 2) == 0)
			l = 1;
		i = 1;
		while (cmd && cmd[i])
		{
			if (i == 1 && ft_memcmp(cmd[i], "-n", 2) != 0)
				ft_putstr_fd(cmd[i], d->pdes[1]);
			else if (ft_memcmp(cmd[i], "-n", 2) != 0 || i != 1)
				ft_putstr_fd(cmd[i], d->pdes[1]);
			if (cmd[i + 1])
				ft_putchar_fd(' ', d->pdes[1]);
			i++;
		}
	}
	l == 0 ? ft_putchar_fd('\n', d->pdes[1]) : ft_putstr_fd("", d->pdes[1]);
	return (0);
}

int			built_in(char **cmd)
{
	if (ft_memcmp(*cmd, "env", 4) == 0)
		return (ft_env(cmd));
	else if (ft_memcmp(*cmd, "cd", 3) == 0)
		return (ft_cd(cmd));
	else if (ft_memcmp(*cmd, "echo", 5) == 0)
		return (ft_echo(cmd));
	else if (ft_memcmp(*cmd, "setenv", 7) == 0)
		return (ft_setenv(cmd));
	else if (ft_memcmp(*cmd, "unsetenv", 9) == 0)
		return (ft_unsetenv(cmd));
	else if (ft_memcmp(*cmd, "export", 7) == 0)
		return (ft_export(cmd));
	return (0);
}
