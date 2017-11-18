/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 12:55:42 by maastie           #+#    #+#             */
/*   Updated: 2017/05/09 12:55:45 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_ctrl_left(void)
{
	int		i;

	if (t->x == 0 || t->line == NULL)
		return ;
	i = t->x - 1;
	while (t->line[i] && t->line[i] == ' ')
		i--;
	while (t->line[i] && t->line[i] != ' ')
		i--;
	if (i == -1)
		ft_khome();
	else if (i > 0 && t->line[i] && t->line[i] != '\0')
		while (t->x > i + 1)
			ft_kleft();
	return ;
}

void		ft_ctrl_right(void)
{
	int		i;

	if (t->line == NULL || t->x == ft_strlen(t->line))
		return ;
	i = t->x;
	while (t->line[i] && t->line[i] == ' ')
		i++;
	while (t->line[i] && t->line[i] != ' ')
		i++;
	while (t->line[i] && t->line[i] == ' ')
		i++;
	if (i < ft_strlen(t->line) && t->line[i] && t->line[i] != '\0')
		while (i > t->x)
			ft_kright();
	return ;
}

void		ft_ctrl_up(void)
{
	int		d;

	d = 0;
	if (t->y > t->ys)
	{
		tputs(tgetstr("up", NULL), 1, ft_putterm);
		t->x = t->x - wws.ws_col;
		if (t->x < 0)
			t->x = 0;
		t->y = t->x / wws.ws_col;
		ft_refresh();
	}
	return ;
}

void		ft_ctrl_down(void)
{
	if (9 + ft_strlen(t->line) < wws.ws_col)
		return ;
	if (t->x + wws.ws_col < ft_strlen(t->line))
	{
		tputs(tgetstr("do", NULL), 1, ft_putterm);
		t->x = t->x + wws.ws_col;
		if (t->x > ft_strlen(t->line))
			t->x = t->x - 9;
		t->y = t->x / wws.ws_col;
	}
	else
		ft_kend();
	ft_refresh();
	return ;
}

void		ctrl_shift(char *buff)
{
	if ((int)buff[5] == 68 && (int)buff[4] == 53)
		ft_ctrl_left();
	else if ((int)buff[5] == 65 && (int)buff[4] == 53)
		ft_ctrl_up();
	else if ((int)buff[5] == 67 && (int)buff[4] == 53)
		ft_ctrl_right();
	else if ((int)buff[5] == 66 && (int)buff[4] == 53)
		ft_ctrl_down();
}
