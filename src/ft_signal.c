/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:30:54 by maastie           #+#    #+#             */
/*   Updated: 2017/07/10 17:30:54 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_better_refresh(void)
{
	ft_clear_term();
	ft_refresh();
}

void		hdnler(int s)
{
	if (s == SIGWINCH)
	{
		ioctl(0, TIOCGWINSZ, &wws);
		ft_better_refresh();
	}
}

void		handler(int s)
{
	if (s == SIGHUP)
		ft_putstr("\n");
	if (s == SIGINT)
	{
		if (t->line && t->line != NULL)
		{
			ft_strdel(&t->line);
			t->line = NULL;
			t->x = 0;
			ft_putstr("\nmaastie$>");
		}
	}
	if (s == SIGQUIT)
		exit(EXIT_SUCCESS);
}

void		ft_signal(void)
{
	signal(SIGTSTP, SIG_IGN);
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
	signal(SIGHUP, handler);
	signal(SIGWINCH, hdnler);
}
