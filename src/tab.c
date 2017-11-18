/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:56:53 by maastie           #+#    #+#             */
/*   Updated: 2017/10/08 15:56:53 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int					mycmp(char *d, char *f)
{
	int				i;

	i = 0;
	while (f && f[i] && d && d[i] && d[i] == f[i])
		i++;
	if (f[i] == '\0')
		return (0);
	return (-1);
}

void				ft_replace_in_line(char *s, char *f)
{
	int				i;

	i = ft_strlen(f);
	while (i > 0)
	{
		ft_delete();
		i--;
	}
	while (s && s[i])
	{
		t->line = add_char(t->line, &s[i]);
		t->x++;
		i++;
	}
}

int					fill_line_c_d(char *f)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(".");
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (mycmp(dp->d_name, f) == 0)
		{
			ft_replace_in_line(dp->d_name, f);
			ft_refresh();
			(void)closedir(dirp);
			return (0);
		}
	}
	(void)closedir(dirp);
	return (0);
}

int			fill_line_o_d(char *f)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(f);
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
		ft_putendl_fd(dp->d_name, STDIN_FILENO);
	(void)closedir(dirp);
	ft_refresh();
	return (0);
}

int					new_folder(char *folder, char *s)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(folder);
	if (dirp == NULL)
		return (-1);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (mycmp(dp->d_name, s) == 0)
		{
			ft_replace_in_line(dp->d_name, s);
			ft_refresh();
			(void)closedir(dirp);
			return (0);
		}
	}
	(void)closedir(dirp);
	return (0);
}

int					c_with_slash(char *s, int i)
{
	char			folder[MAXPATHLEN];
	char			n[MAXPATHLEN];
	int				st;

	st = 0;
	while (st <= i)
	{
		folder[st] = s[st];
		folder[++st] = '\0';
	}
	if (access(folder, F_OK) == 0)
	{
		st = 0;
		if (!s[++i])
		{
			ft_strdel(&s);
			return (fill_line_o_d(folder));
		}
		while (s && s[i])
		{
			n[st] = s[i];
			n[++st] = '\0';
			i++;
		}
		ft_strdel(&s);
		return (new_folder(folder, n));
	}
	ft_strdel(&s);
	return (0);
}

int			completion2(char *s, int p, int t)
{
	char	*w;
	int		i;

	i = 0;
	if ((w = (char *)malloc(sizeof(char) * (t + 1))) == NULL)
		return (-1);
	t = p;
	while (s && s[t - 1] && t > 0 && s[t  -1] != ' ')
		t--;
	while (s && s[t] && s[t] != ' ' && t <= p)
	{
		w[i] = s[t];
		w[++i] = '\0';
		t++;
	}
	i--;
	while (w && w[i])
	{
		if (w[i] == '/')
			return (c_with_slash(w, i));
		i--;
	}
	if (fill_line_o_d(w) == 0)
	{
		ft_strdel(&w);
		return (0);
	}
	else if (w && fill_line_c_d(w) == -1)
		ft_strdel(&w);
	else
		ft_strdel(&w);
	return (0);
}

int			completion(char *s, int p)
{
	int		i;
	int		r;

	i = p;
	r = 1;
	while (t->line && t->line[i - 1] && i > 0 && t->line[i - 1] != ' ')
		i--;
	while (t->line && t->line[i] && t->line[i] != ' ' && i <= p)
	{
		r++;
		i++;
	}
	return (completion2(s, p, r));
}

int			ft_tab(void)
{
	int		p;

	p = t->x;
	if (!t->line)
		return (0);
	else
	{
		if (t->line[p] && ((t->line[p] != ' ') && t->line[p] != '\0'))
			return (0);
		else if (t->line[p - 1] && t->line[p - 1] == ' ')
			return (0);
		else
		{
			p = t->x - 1;
			return (completion(t->line, p));
		}
	}
	return (0);	
}