/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2_term.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:07:41 by maastie           #+#    #+#             */
/*   Updated: 2017/05/09 13:07:44 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

char		*del_index(char *s, int index)
{
	char	*new;
	int		k;

	if (ft_strlen(s) == 1)
	{
		ft_strdel(&s);
		return (s);
	}
	if ((new = (char*)malloc(sizeof(char) * (ft_strlen(s)))) == NULL)
		return (NULL);
	ft_bzero(new, ft_strlen(s));
	new = ft_strncpy(new, s, index);
	k = index;
	while (s && s[index + 1])
	{
		new[k] = s[index + 1];
		new[++k] = '\0';
		index++;
	}
	ft_strdel(&s);
	return (new);
}

void		ft_khome(void)
{
	int		d;

	if (t->x > wws.ws_col)
	{
		d = t->x;
		while (d / wws.ws_col > 0)
		{
			d = d - wws.ws_col;
			t->y--;
		}
	}
	while (t->x >= 0)
	{
		ft_kleft();
		if (t->x == 0)
		{
			ft_kleft();
			break ;
		}
	}
	return ;
}

void		ft_kend(void)
{
	while (t->x < ft_strlen(t->line))
	{
		ft_kright();
		if (t->x == ft_strlen(t->line) - 1)
		{
			ft_kright();
			break ;
		}
	}
	return ;
}

int			ft_putterm(int c)
{
	write(1, &c, 1);
	return (1);
}
