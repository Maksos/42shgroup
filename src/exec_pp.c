/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:06:38 by maastie           #+#    #+#             */
/*   Updated: 2017/10/03 14:06:38 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		exec_red(t_pp *r)
{
	t_red	*t;

	t = r->red;
	if (red_fd(t) == -1)
		return (-1);
	// int	i;

	// ft_putendl("OKKKK");
	// i = 0;
	// while (t->cmd && t->cmd[i])
	// 	ft_putendl(t->cmd[i++]);
	return (0);
}

int		exec_red_f(t_pp *r)
{
	pid_t	f;

	if ((f = fork()) == -1)
		return (-1);
	d->pdes[0] = STDIN_FILENO;
	d->pdes[1] = STDOUT_FILENO;	
	if (f == 0)
	{
		if ((d->andor = red_fd(r->red)) == -1)
			exit(d->andor);
		else
			exit(d->andor = exec_it(r->red, d->env));
	}
	else
	{
		waitpid(f, &d->andor, WUNTRACED | WCONTINUED);
		return (d->andor);
	}
	return (d->andor);
}

int		exec_solo(t_pp *c)
{
	t_pp	*t;

	t = c;
	if (pipe(d->pdes) == -1)
		return (-1); // error pipe failed;
	d->pdes[0] = STDIN_FILENO;
	d->pdes[1] = STDOUT_FILENO;
	if (t->pipe)
		return (d->andor = ftt_pipe(t->pipe));
	else if (check_built_in(t->red->cmd) == 0)
	{
		if ((d->andor = exec_red(t)) == -1)
			return (d->andor);
		return (d->andor = exec_it(t->red, d->env));
	}
	else
		return (d->andor = exec_red_f(t));

	return (d->andor);
}

int		exec_condition(t_pp *c)
{
	if (c->act && ft_memcmp(c->act, "&&", 3) == 0)
	{
		if (exec_solo(c) != 0 || exec_pp(c->nxt) != 0)
			return (-1);
	}
	else if (c->act && ft_memcmp(c->act, "||", 3) == 0)
	{
		if (exec_solo(c) != 0)
		{
			if (exec_pp(c->nxt) != 0)
				return (-1);
		}
		else
		{
			c = c->nxt;
			return (exec_pp(c->nxt));
		}
	}
	return (0);
}

int		exec_pp(t_pp *c)
{
	t_pp	*t;

	t = c;
	while (t)
	{
		if (!t->act || (t->act && ft_memcmp(t->act, ";", 2) == 0))
		{
			if (exec_solo(t) == -1)
				return (-1);
		}
		else
			 return (exec_condition(t));
		if (t)
			t = t->nxt;
	}
	return (0);
}