/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_red.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:18:58 by maastie           #+#    #+#             */
/*   Updated: 2017/09/28 19:18:59 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		operand(char *s, int i)
{
	if (s && s[i] == '>')
	{
		if (s[i + 1] && s[i + 2] && s[i + 1] == s[i] && s[i + 2] == s[i])
			return (-2);
		else if ((s[i + 1] && s[i + 2] && s[i + 1] == s[i] && s[i + 2] == '&')
			|| (s[i + 1] && s[i + 1] == '&'))
			return (-1);
		return (1);
	}
	else if (s && s[i] == '<')
	{
		if ((s[i + 1] && s[i + 2] && s[i + 1] == s[i] && s[i + 2] == s[i])
			|| (s[i + 1] && s[i + 2] && s[i + 1] == s[i] && s[i + 2] == '&'))
			return (-2);
		else if (s[i + 1] && s[i + 1] == '&')
			return (-1);
		return (1);
	}
	return (0);
}

int		ft_n_red(char *s, int i, t_red *r)
{
	if (s[i] && s[i + 1] && s[i + 1] == s[i])
	{
		if (s[i] == '>')
			r->act = ft_strdup(">>");
		else if (s[i] == '<')
			r->act = ft_strdup("<<");
		i = i + 2;
	}
	else if (s[i] && s[i + 1] && s[i + 1] != s[i])
	{
		if (s[i] == '<')
			r->act = ft_strdup("<");
		else if (s[i] == '>')
			r->act = ft_strdup(">");
		i = i + 1;
	}
	// while (s && s[i] && (s[i] == ' ' || s[i] == '\t'))
	// 	i++;
	if (!s[i] || (r->nxt = (t_red *)malloc(sizeof(t_red))) == NULL)
		return (-1);
	r->nxt->act = NULL;
	r->nxt->cmd = NULL;
	r->nxt->nxt = NULL;
	return (ft_b_f_red(s, r->nxt, i));
}

int		ft_b_f_red(char *s, t_red *r, int i)
{
	char	c;
	char	*t;

	t = NULL;
	while (s && s[i])
	{
		if (s && s[i] && (s[i]  == ' ' || s[i] == '\t'))
		{
			// fcnt space_or_tab
			while (s && s[i] && (s[i]  == ' ' || s[i] == '\t'))
				i++;
			if (t)
			{
				r->cmd = add_new(r->cmd, t, 0, 0);
				ft_strdel(&t);
			}
			if (!s[i])
				return (0);
		}
		if (operand(s, i) == -2)
		{
			//fcnt operand
			if (t)
				ft_strdel(&t);
			return (-1);
		}
		else if (operand(s, i) == 1)
		{
			if (t)
			{
				r->cmd = add_new(r->cmd, t, 0, 0);
				ft_strdel(&t);
			}
			return (ft_n_red(s, i, r));
		}
		if (s && s[i] && (s[i] == '"' || s[i] == '\''))
		{
			// fcnt add_without_quote
			c = s[i++];
			while (s && s[i] != c)
				t = ft_adchar(t, s[i++]);
			if (t)
			{
				r->cmd = add_new(r->cmd, t, 0, 0);
				ft_strdel(&t);
			}
		}
		else if (s && s[i])
			t = ft_adchar(t, s[i]);
		if (!s[i + 1])
		{
			// last
			if (t)
			{
				r->cmd = add_new(r->cmd, t, 0, 0);
				ft_strdel(&t);
			}
		}
		i++;
	}
	return (0);
}

int			ft_fill_red(t_pp *p)
{
	if ((p->red = (t_red *)malloc(sizeof(t_red))) == NULL)
		return (-1);
	p->red->act = NULL;
	p->red->cmd = NULL;
	p->red->nxt = NULL;
	return (ft_b_f_red(p->cmd, p->red, 0));
}

int			pp_red()
{
	t_pp	*t;
	t_pp	*p;

	t = d->bpp;
	while (t)
	{
		if (t->pipe)
		{
			p = t->pipe;
			while (p)
			{
				if (ft_fill_red(p) == -1 || check_red_data(p->red) == -1)
					return (-1);
				p = p->nxt;
			}
		}
		else if (!t->pipe &&
			(ft_fill_red(t) == -1 || check_red_data(t->red) == -1))
			return (-1);
		t = t->nxt;
	}
	// return (-1);
	return (0);
}