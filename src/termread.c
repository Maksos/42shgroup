/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 16:42:07 by maastie           #+#    #+#             */
/*   Updated: 2017/07/10 16:42:08 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			ft_clear_term(void)
{
	pid_t	tt;

	if ((tt = fork()) == -1)
		return (-1);
	if (tt == 0)
		execve("/usr/bin/clear", NULL, d->env);
	else
	{
		wait(NULL);
		return (0);
	}
	return (0);
}

int			what_key_input(char *buff)
{
	if ((int)buff[0] == 127 && (int)buff[1] == '\0')
		ft_delete(); // des deux sens
	else if ((int)buff[0] == 27 && (int)buff[1] == 91 && (int)buff[2] == 51)
	{
		if (t->x > 0 && t->line[t->x])
		{
			ft_kright();
			if (t->x > 0 && t->line[t->x - 1])
				ft_delete();			
		}
	}
	else if ((int)buff[0] == 27 && (int)buff[3] == '\0')
		arrows_more(buff);
	else if ((int)buff[0] == 27 && (int)buff[3] != '\0')
		ctrl_shift(buff);
	else if ((int)buff[0] == 10 && (int)buff[1] == '\0')
		return (ft_kenter());
	else if ((int)buff[0] == 9 && (int)buff[1] == '\0')
		return (ft_tab());
	else if (((int)buff[0] == -61 && (int)buff[1] == -89 && (int)buff[2] == 0)
	|| ((int)buff[0] == -30 && (int)buff[1] == -119 && (int)buff[2] == -120)
	|| ((int)buff[0] == -30 && (int)buff[1] == -120 && (int)buff[2] == -102))
		alt_xcv(buff);
	else if ((ft_isascii(buff[0]) == 1) && buff[1] == '\0')
	{
		if (t->line == NULL)
			t->line = ft_strdup(buff);
		else
			t->line = add_char(t->line, buff);
		t->x++;
		ft_refresh();
	}
	return (0);
}

int			ft_kenter(void)
{
	if (quoted() == 0)
		if (t->line && t->line[0] != '\0')
		{
			t->history = add_new(t->history, t->line, 0, 0);
			while (t->history && t->history[t->hi + 1])
				t->hi++;
			ft_kend();
			t->x = 0;
			ft_putendl_fd("", STDOUT_FILENO);
			if (pp(t->line) == -1 || pp_in() == -1 || pp_red() == -1
				|| exec_pp(d->fpp) == -1)
				return (-1);
			dup2(STDIN_FILENO, 0);
			dup2(STDOUT_FILENO, 1);
			dup2(STDERR_FILENO, 2);
			d->ph = 0;
			ft_free_pp(d->bpp);
			ft_strdel(&t->line);
			ft_putstr("maastie$>");
			return (0);
		}
	!t->line ? ft_putstr("\nmaastie$>") : ft_putstr("");
	return (0);
}

int			termread(void)
{
	char	buff[7];

	if (isatty(STDIN_FILENO) != 0 && init_termcap(STDIN_FILENO) != 0)
		return (-1);
	ft_signal();
	(void)ft_memset((void *)buff, 0, 6);
	ft_bzero(buff, sizeof(buff));
	buff[read(STDIN_FILENO, buff, 6)] = '\0';
	if ((int)buff[0] == 12 && (int)buff[1] == '\0')
	{
		ft_clear_term();
		ft_refresh();
	}
	if ((int)buff[0] == 4 && (int)buff[1] == 0 && !t->line)
	{
		if (!t->line)
			return (-2);
		return (1);
	}
	if (what_key_input(buff) == -1)
		return (1);
	return (termread());
}
