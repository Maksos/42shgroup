/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 13:01:23 by maastie           #+#    #+#             */
/*   Updated: 2017/05/09 13:01:24 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_refresh(void)
{
	int		s;

	s = t->x + 9;
	while (s > 0)
	{
		tputs(tgetstr("le", NULL), 1, ft_putterm);
		s--;
	}
	while (t->line && t->line[s++])
		if (t->line[s] == '\n')
			tputs(tgetstr("up", NULL), 1, ft_putterm);
	tputs(tgetstr("cd", NULL), 1, ft_putterm);
	ft_putstr("maastie$>");
	if (t->line && t->line != NULL)
		ft_putstr(t->line);
	s = t->x;
	if (t->line && t->line != NULL)
		t->x = ft_strlen(t->line);
	while (s < t->x)
		ft_kleft();
	t->y = (t->x + 9) / wws.ws_col;
	return ;
}

void		ft_delete(void)
{
	int		s;

	if (9 + t->x >= 10)
	{
		tputs(tgetstr("le", NULL), 1, ft_putterm);
		t->x--;
		s = t->x;
		t->line = del_index(t->line, t->x);
		if (t->line && t->line[t->x] && t->line[t->x] == '\n')
			t->y--;
		while (s > 0)
		{
			tputs(tgetstr("le", NULL), 1, ft_putterm);
			s--;
		}
		s = t->x;
		tputs(tgetstr("dc", NULL), 1, ft_putterm);
		ft_refresh();
	}
	return ;
}

char		*add_char(char *s, char *n)
{
	char	*l;
	int		i;
	int		k;

	i = 0;
	k = t->x;
	if ((l = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2))) == NULL)
		return (NULL);
	while (s && i < t->x)
	{
		l[i] = s[i];
		i++;
	}
	l[i++] = n[0];
	while (s && s[k])
		l[i++] = s[k++];
	l[i] = '\0';
	ft_strdel(&s);
	return (l);
}
