/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_in.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:34:35 by maastie           #+#    #+#             */
/*   Updated: 2017/09/27 18:34:36 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			ft_fill_for_pipe(t_pp *l, int i)
{
	char	c;

	while (d->fpp->cmd && d->fpp->cmd[i])
	{
		if (d->fpp->cmd[i] && (d->fpp->cmd[i] == '\'' || d->fpp->cmd[i] == '"'))
		{
			c = d->fpp->cmd[i++];
			l->cmd = ft_adchar(l->cmd, c);
			while (d->fpp->cmd[i] != c)
				l->cmd = ft_adchar(l->cmd, d->fpp->cmd[i++]);
			l->cmd = ft_adchar(l->cmd, d->fpp->cmd[i++]);
		}
		if (d->fpp->cmd[i] == '|')
		{
			l->act = ft_strdup("|");
			if ((l->nxt = (t_pp *)malloc(sizeof(t_pp))) == NULL)
				return (-1);
			l->nxt->act = NULL;
			l->nxt->cmd = NULL;
			l->nxt->nxt = NULL;
			l->nxt->pipe = NULL;
			return (ft_fill_for_pipe(l->nxt, ++i));
		}
		else
			l->cmd = ft_adchar(l->cmd, d->fpp->cmd[i]);
		i++;
	}
	return (0);	
}

int			ft_fill_data_in()
{
	int		i;
	char	c;

	i = 0;
	while (d->fpp->cmd && d->fpp->cmd[i])
	{
		if (d->fpp->cmd[i] == '\'' || d->fpp->cmd[i] == '"')
		{
			c = d->fpp->cmd[i++];
			while (d->fpp->cmd[i] != c)
				i++;
		}
		if (d->fpp->cmd[i] == '|')
		{
			if ((d->fpp->pipe = (t_pp *)malloc(sizeof(t_pp))) == NULL)
				return (-1);
			d->fpp->pipe->act = NULL;
			d->fpp->pipe->cmd = NULL;
			d->fpp->pipe->pipe = NULL;
			d->fpp->pipe->nxt = NULL;
			return (ft_fill_for_pipe(d->fpp->pipe, 0));
		}
		i++;
	}
	return (0);
}

int			pp_in()
{
	while (d->fpp)
	{
		if (ft_fill_data_in() == -1
			|| check_pipe_data(d->fpp->pipe) == -1)
			return (-1);
		d->fpp = d->fpp->nxt;
	}
	d->fpp = d->bpp;
	return (0);
}