/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 16:25:53 by maastie           #+#    #+#             */
/*   Updated: 2017/10/03 16:25:53 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int			ft_pipe(t_pp *p)
{
	pid_t	f;

	if (pipe(d->pdes) == -1 || (f = fork()) == -1)
		return (-1);
	else
	{
		d->ph++;
		if (f == 0)
		{
			dup2(d->pdes[1], STDOUT_FILENO);
			close(d->pdes[0]);
			exit(d->andor = exec_red_f(p));
		}
		else
		{
			waitpid(f, &d->andor, WUNTRACED | WCONTINUED | WNOHANG);
			dup2(d->pdes[0], STDIN_FILENO);
			close(d->pdes[1]);
			p = p->nxt;
			if (p->nxt)
				exit(d->andor = ftt_pipe(p));
			else
				return(d->andor = exec_red_f(p));
		}
	}
	return (0);
}

int		ftt_pipe(t_pp *p)
{
	pid_t	f;

	if ((f = fork()) == -1)
		return (-1);
	else
	{
		if (f == 0)
			exit(ft_pipe(p));
		else
			waitpid(f, &d->andor, WUNTRACED | WCONTINUED);
	}
	return (d->andor);
}
