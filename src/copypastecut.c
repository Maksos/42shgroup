/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copypastecut.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 16:05:34 by maastie           #+#    #+#             */
/*   Updated: 2017/05/10 16:05:34 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_straddin(int i, int l)
{
	char	*n;

	if ((n = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return ;
	while (t->line && l < t->x)
	{
		n[l] = t->line[l];
		l++;
	}
	i = 0;
	while (t->xcpy && t->xcpy[i])
		n[l++] = t->xcpy[i++];
	i = t->x;
	while (t->line && t->line[i])
		n[l++] = t->line[i++];
	n[l] = '\0';
	if (t->line && t->line != NULL)
		ft_strdel(&t->line);
	t->line = n;
}

void		alt_xcv(char *buff)
{
	if ((int)buff[0] == -61 && (int)buff[1] == -89 && (int)buff[2] == 0)
	{
		if (t->xcpy && t->xcpy != NULL && t->line)
			ft_strdel(&t->xcpy);
		t->line ? (t->xcpy = ft_strdup(t->line)) : t->line;
	}
	else if ((int)buff[0] == -30
		&& (int)buff[1] == -119 && (int)buff[2] == -120)
	{
		if (t->xcpy && t->xcpy != NULL && t->line)
			ft_strdel(&t->xcpy);
		if (t->line)
		{
			t->xcpy = ft_strdup(t->line);
			ft_strdel(&t->line);
			ft_refresh();
			t->x = 0;
		}
	}
	else if ((int)buff[0] == -30
		&& (int)buff[1] == -120 && (int)buff[2] == -102)
	{
		ft_straddin((ft_strlen(t->line) + ft_strlen(t->xcpy)), 0);
		ft_refresh();
	}
}

int			quote_in(char *s, int i)
{
	char	l;
	int		o;

	while (s && s[i])
	{
		if (s[i] == '\'' || s[i] == '\"')
		{
			l = s[i];
			o = 1;
			i++;
			while (s[i] && s[i] != l)
				i++;
			if (s[i] == l)
				o = 2;
			else if (s[i] == '\0' && o == 1)
				return (1);
			else if (o == 2 && s[i] == '\0')
				return (0);
			else
				return (quote_in(s, i));
		}
		if (s[i])
			i++;
	}
	return (0);
}

int			quoted(void)
{
	if (quote_in(t->line, 0) == 0)
		return (0);
	else
	{
		t->line = ft_adchar(t->line, '\n');
		t->x++;
		t->y++;
		ft_putstr_fd("\n<Quote>", STDERR_FILENO);
	}
	return (1);
}
