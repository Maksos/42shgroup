/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 17:20:50 by maastie           #+#    #+#             */
/*   Updated: 2017/07/10 17:20:51 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void				iiterm(void)
{
	t->line = NULL;
	t->xcpy = NULL;
	t->x = 0;
	t->hi = 0;
	t->history = NULL;
	t->ys = 0;
	t->y = 0;
	return ;
}

int					check_env(void)
{
	int				i;

	i = 0;
	while (d->env && d->env[i])
		if (ft_memcmp("TERM=xterm-256color", d->env[i++], 19) == 0)
			return (0);
	return (1);
}

int					init_termcap(int fd)
{
	struct termios	term;

	tcgetattr(fd, &term);
	term.c_lflag &= ~(ECHO | ICANON);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(fd, TCSADRAIN, &term);
	if (tgetent(NULL, getenv("TERM")) == -1)
	{
		if (check_env() == 0)
		{
			if (tgetent(NULL, "xterm-256color") == -1)
				return (-1);
		}
		else
			return (1);
	}
	tputs(tgetstr("am", NULL), 1, ft_putterm);
	return (0);
}

void				default_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= (ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	return ;
}

int					begin_termcaps_read(void)
{
	int				r;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &wws);
	iiterm();
	if (init_termcap(STDIN_FILENO) != 0)
		return (ft_error(5, -1));
	r = 0;
	while (r == 0)
	{
		ft_refresh();
		r = termread();
		default_term();
		if (r == -1)
			return (ft_error(6, -1));
		if (r == 1)
		{
			ft_strdel(&t->line);
			ft_free_pp(d->bpp);
			r = 0;
		}
		else if (r == -2)
			break ;
	}
	default_term();
	return (0);
}
