/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:52:01 by maastie           #+#    #+#             */
/*   Updated: 2017/10/10 14:52:01 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			get_opt_ex(char **s, char *opt)
{
	int		i;

	i = 1;
	while (s && s[i])
	{
		if (s[i] && s[i][0] && s[i][0] == '-' && s[i][1])
		{
			if (!s[i][1] || s[i][2])
				return (-1); // error argument not valid
			else if (s[i][1] && s[i][1] == 'P')
			{
				ft_putendl("Ok");
				*opt = 'P';
			}
		}
		i++;
	}
	return (0);
}

int		ft_export(char **cmd)
{
	char	opt;
	int		i;

	opt = '0';
	i = 0;
	if (get_opt_ex(cmd, &opt) == -1 || clear_opt(cmd) == -1)
		return (-1);
	if (!cmd[1])
	{
		while (d->env && d->env[i])
		{
			if (opt == 'P')
				ft_putstr("typeset -x : ");
			ft_putendl(d->env[i++]);
		}
		return (0);
	}
	return (0);
}