/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 15:55:03 by maastie           #+#    #+#             */
/*   Updated: 2017/10/05 15:55:03 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		check_pipe_data(t_pp *p)
{
	t_pp *t;

	t = p;
	while (t)
	{
		if (!t->act && !t->cmd)
			return (-1);
		if (t->act && !t->cmd)
			return (-1);
		if (t->act && t->cmd && !t->cmd[0])
			return (-1);
		// check si cmd n est pas rempli de >&
		t = t->nxt;
	}
	return (0);
}

int		check_red_data(t_red *r)
{
	t_red *t;

	t = r;
	while (t)
	{
		if (!t->act && !t->cmd)
			return (-1);
		if (t->act && !t->cmd)
			return (-1);
		if (t->act && t->cmd && !t->cmd[0])
			return (-1);
		// check si cmd n est pas rempli de >&
		t = t->nxt;
	}
	return (0);
}