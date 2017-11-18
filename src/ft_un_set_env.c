/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_un_set_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:51:35 by maastie           #+#    #+#             */
/*   Updated: 2017/10/10 14:51:35 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		in_tab(char *r)
{
	int	i;
	int	a;

	i = 0;
	while (d->env && d->env[i])
	{
		a = 0;
		while (d->env[i][a] == r[a])
			a++;
		if (r[a] == '\0')
			return (0);
		i++;
	}
	return (-1);
}

int		ft_search_and_d(char *r)
{
	int	i;
	int	a;

	i = 0;
	while (d->env && d->env[i])
	{
		a = 0;
		while (d->env[i][a] && d->env[i][a] == r[a])
			a++;
		if (!r[a] && d->env[i][a] && d->env[i][a] == '=')
		{
			d->env = del_and_ajust_tab(d->env, i);
			return (0);
		}
		i++;
	}
	return (-1);
}

int		ft_unsetenv(char **cmd)
{
	if (!cmd[1])
		return (-1); // error argument
	if (in_tab(cmd[1]) == 0)
	{
		if (ft_search_and_d(cmd[1]) == -1)
			return (-1);
	}
	return (0);
}

int		nequal(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s1[i])
	{
		if (s1[i] == '=')
			return (-1);
		i++;
	}
	i = 0;
	while (s2 && s2[i])
	{
		if (s2[i] == '=')
			return (-1);
		i++;
	}
	return (0);
}

char			*ft_concat_s(char *p, char *pre)
{
	char		*r;
	int			i;
	int			a;

	if ((r = (char *)malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(pre)))) == NULL)
		return (NULL);
	i = 0;
	a = 0;
	while (pre && pre[i])
	{
		r[a] = pre[i++];
		r[++a] = '\0';
	}
	i = 0;
	while (p && p[i])
	{
		r[a] = p[i++];
		r[++a] = '\0';
	}
	return (r);
}

int		ft_setenv(char **cmd)
{
	char	*nv;
	char	*nnv;

	nv = NULL;
	if ((!cmd[1] || !cmd[2] || !cmd[3]) || (cmd[1] && cmd[2] && cmd[3] && cmd[4]))
		return (-1);// error argument
	if (cmd[3][0] != '0' && cmd[3][0] != '1')
		return (-1); // error argument
	if (nequal(cmd[1], cmd[2]) == -1)
		return (-1); // error mequal
	if ((nv = ft_concat_s("=", cmd[1])) == NULL)
		return (-1); //error malloc
	if (in_tab(nv) == 0)
	{
		if (cmd[3][0] == '1' && ft_search_and_c(nv, cmd[2], nv) == NULL)
		{
			ft_strdel(&nv);
			return (-1);
		}
		if (nv && nv != NULL)
			ft_strdel(&nv);
	}
	else
	{
		nnv = ft_concat_s(cmd[2], nv);
		d->env = add_new(d->env, nnv, 0, 0);
		ft_strdel(&nv);
		ft_strdel(&nnv);
	}
	return (0);
}