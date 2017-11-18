/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:35:34 by maastie           #+#    #+#             */
/*   Updated: 2017/07/10 15:35:34 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_free_red(t_red *b)
{
	t_red	*t;

	while (b)
	{
		if (b->act)
			ft_strdel(&b->act);
		if (b->cmd)
			ft_free_tab(b->cmd);
		t = b;
		b = b->nxt;
		free(t);
	}
}

void	ft_free_pp(t_pp *b)
{
	struct s_pp		*t;

	while (b)
	{
		if (b->pipe)
			ft_free_pp(b->pipe);
		if (b->red)
			ft_free_red(b->red);
		if (b->act)
			ft_strdel(&b->act);
		if (b->cmd)
			ft_strdel(&b->cmd);
		t = b;
		b = b->nxt;
		free(t);
	}
}

char		**ft_free_tab(char **tabl)
{
	int		i;

	i = 0;
	if (!tabl)
		return (NULL);
	while (tabl && tabl[i] != NULL)
	{
		free(tabl[i]);
		i++;
	}
	if (tabl && tabl != NULL)
		free(tabl);
	return (NULL);
}

void		ft_free_all(void)
{
	if (t->line && t->line != NULL)
		ft_strdel(&t->line);
	if (t->history && t->history != NULL)
		t->history = ft_free_tab(t->history);
	if (t->xcpy && t->xcpy != NULL)
		ft_strdel(&t->xcpy);
	free(t);
	if (d->env && d->env != NULL)
		ft_free_tab(d->env);
	free(d);
}
