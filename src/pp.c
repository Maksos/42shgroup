/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:58:56 by maastie           #+#    #+#             */
/*   Updated: 2017/09/27 17:58:56 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		check_in(char *s, int i)
{
	if (s[i] == ';' && s[i + 1] && s[i + 1] == ';')
		return (-1);
	else if (s[i] == '|' && s[i + 1] && s[i + 1] == '|'
		&& s[i + 2] && s[i + 2] == '|')
		return (-1);
	else if (s[i] == '&' && s[i + 1] && s[i + 1] == '&'
		&& s[i + 2] && s[i + 2] == '&')
		return (-1);
	return (0);
}

int		ft_fill_pp(char *s, int i)
{
	char	c;

	while (s && s[i])
	{
		if (check_in(s, i) == -1)
			return (-1);
		if (s[i] == ';')
			return (ft_new_pp(s, i));
		else if (s[i] == '|' && s[i + 1] && s[i + 1] == '|')
			return (ft_new_pp(s , ++i));
		else if (s[i] == '&' && s[i + 1] && s[i + 1] == '&')
			return (ft_new_pp(s, ++i));
		else if (s[i] == '\'' || s[i] == '"')// || s[i] == '`')
		{
			c = s[i++];
			d->fpp->cmd = ft_adchar(d->fpp->cmd, c);
			while (s[i] && s[i] != c)
				d->fpp->cmd = ft_adchar(d->fpp->cmd, s[i++]);
			d->fpp->cmd = ft_adchar(d->fpp->cmd, c);
		}
		else
			d->fpp->cmd = ft_adchar(d->fpp->cmd, s[i]);
		i++;
	}
	return (0);
}

int		ft_new_pp(char *s, int i)
{
	int	si;

	si = i + 1;
	while (s && s[si])
		si++;
	if (--si == i && s[i] != ';')
		return (-1);
	else if (si == i && s[i] == ';')
		return (0);
		// faire un fcnt et check direct si la line est rempli de tab ou d espace
	if ((d->fpp->nxt = (t_pp *)malloc(sizeof(t_pp))) == NULL)
		return (-1);
	if (s[i] == ';')
		d->fpp->act = ft_strdup(";");
	else if (s[i] == '|')
		d->fpp->act = ft_strdup("||");
	else
		d->fpp->act = ft_strdup("&&");
	d->fpp = d->fpp->nxt;
	d->fpp->nxt = NULL;
	d->fpp->red = NULL;
	d->fpp->act = NULL;
	d->fpp->cmd = NULL;
	d->fpp->pipe = NULL;
	if (ft_fill_pp(s, ++i) == -1)
		return (-1);
	return (0);
}

int		pp(char *s)
{
	if ((d->bpp = (t_pp *)malloc(sizeof(t_pp))) == NULL)
		return (-1);
	d->fpp = d->bpp;
	d->fpp->red = NULL;
	d->fpp->nxt = NULL;
	d->fpp->act = NULL;
	d->fpp->cmd = NULL;
	d->fpp->pipe = NULL;
	if (ft_fill_pp(s, 0) == -1)
	{
		ft_putendl("ERROR parse");
		return (-1);
	}
	// d->fpp = d->bpp;
	// ft_putendl("Before");
	// while (d->fpp)
	// {
	// 	if (d->fpp->act)
	// 		ft_putendl(d->fpp->act);
	// 	if (d->fpp->cmd)
	// 		ft_putendl(d->fpp->cmd);
	// 	d->fpp = d->fpp->nxt;
	// }
	// ft_putendl("End before");
	d->fpp = d->bpp;
	return (0);
}