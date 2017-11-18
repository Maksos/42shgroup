/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:58:14 by maastie           #+#    #+#             */
/*   Updated: 2017/05/09 12:58:15 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_kleft(void)
{
	if (t->x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putterm);
		t->x--;
	}
	t->y = (t->x + 9) / wws.ws_col;
}

void		ft_kright(void)
{
	if (t->line && t->x <= (ft_strlen(t->line) - 1))
	{
		if ((9 + t->x) > 0 && ((t->x + 10) % wws.ws_col) == 0)
			tputs(tgetstr("do", NULL), 1, ft_putterm);
		else
			tputs(tgetstr("nd", NULL), 1, ft_putterm);
	}
	if (t->x < ft_strlen(t->line))
		t->x++;
	t->y = (9 + t->x) / wws.ws_col;
}

void		ft_kdown(void)
{
	if (t->history == NULL)
		return ;
	while (t->x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putterm);
		t->x--;
	}
	tputs(tgetstr("cd", NULL), 1, ft_putterm);
	ft_strdel(&t->line);
	if (t->history != NULL && t->history[t->hi + 1])
	{
		ft_strdel(&t->line);
		t->line = ft_strdup(t->history[t->hi + 1]);
		t->hi++;
	}
	ft_putstr(t->line);
	t->x = ft_strlen(t->line);
}

void		ft_kup(void)
{
	if (t->history == NULL)
		return ;
	while (t->x > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putterm);
		t->x--;
	}
	tputs(tgetstr("cd", NULL), 1, ft_putterm);
	if (t->history != NULL)
	{
		ft_strdel(&t->line);
		if (t->history[t->hi])
			t->line = ft_strdup(t->history[t->hi]);
		ft_putstr(t->line);
		t->x = ft_strlen(t->line);
		if (t->hi > 0)
			t->hi--;
	}
}

void		arrows_more(char *buff)
{
	if ((int)buff[2] == 68)
		ft_kleft();
	else if ((int)buff[2] == 66)
		ft_kdown();
	else if ((int)buff[2] == 67)
		ft_kright();
	else if ((int)buff[2] == 65)
		ft_kup();
	else if ((int)buff[2] == 72)
		ft_khome();
	else if ((int)buff[2] == 70)
		ft_kend();
}
