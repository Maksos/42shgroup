/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 14:51:01 by maastie           #+#    #+#             */
/*   Updated: 2017/10/10 14:51:02 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

char			*ft_concat(char *p, char *pre) // tools
{
	char		*r;
	int			i;
	int			a;

	if ((r = (char *)malloc(sizeof(char) * (ft_strlen(p) + ft_strlen(pre)))) == NULL)
		return (NULL);
	i = 0;
	a = 0;
	while (pre && pre[i])
	{
		r[a] = pre[i++];
		r[++a] = '\0';
	}
	i = 0;
	while (p && p[i])
	{
		r[a] = p[i++];
		r[++a] = '\0';
	}
	if (p && p != NULL)
		ft_strdel(&p);
	return (r);
}

char			*fill_r(char *s, char *r, char *d) // tools ?
{
	int		i;
	int		a;

	i = 0;
	while (s && s[i] && s[i] == r[i])
		i++;
	if (!s[i])
		return (NULL);
	if ((d = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1))) == NULL)
		return (NULL);
	a = 0;
	while (s && s[i])
	{
		d[a] = s[i++];
		d[++a] = '\0';
	}
	return (d);
}

char			*ft_search_and_r(char *ref, char *fill)// tools
{
	int		i;
	int		a;

	i = 0;
	while (d->env && d->env[i])
	{
		a = 0;
		if (d->env[i][0] == ref[a])
		{
			while (ref[a] && d->env[i][a] && d->env[i][a] == ref[a])
				a++;
			if (!ref[a])
				return (fill_r(d->env[i], ref, fill));
		}
		i++;
	}
	return (NULL);
}

char		*fill_c(char *s, char *d, char *p)
{
	int		i;
	int		a;
	char	*r;

	if ((r = (char *)malloc(sizeof(char) *
		(ft_strlen(d) + ft_strlen(p) + 1))) == NULL)
		return (NULL);
	i = 0;
	while (p && p[i])
	{
		r[i] = p[i];
		r[++i] = '\0';
	}
	a = 0;
	while (d && d[a])
	{
		r[i] = d[a++];
		r[++i] = '\0';
	}
	if (s && s != NULL)
		ft_strdel(&s);
	return (r);
}

char		*ft_search_and_c(char *r, char *c, char *p) // tools
{
	int		i;
	int		a;

	i = 0;
	while (d->env && d->env[i])
	{
		a = 0;
		if (d->env[i][a] == r[a])
		{
			while (r[a] && d->env[i][a] == r[a])
				a++;
			if (!r[a])
				return (d->env[i] = fill_c(d->env[i], c, p));
		}
		i++;
	}
	return (NULL);
}

int			cd_home(char **cmd, char opt[1])
{
	char	*np;
	char	*no;

	np = NULL;
	no = NULL;
	if ((np = ft_search_and_r("HOME=", np)) == NULL)
		return (-1); // error HOME not set
	if (chdir(np) == -1)
		return (-1); // error couldnt acces to HOME
	if ((no = ft_search_and_r("PWD=", no)) == NULL)
		no = NULL;
	if (ft_search_and_c("PWD=", np, "PWD=") == NULL)
		d->env = add_new(d->env, np = ft_concat(np, "PWD="), 0, 0);
	if (no && ft_search_and_c("OLDPWD=", no, "OLDPWD=") == NULL)
		d->env = add_new(d->env, no = ft_concat(no, "OLDPWD="), 0, 0);
	if (no && no != NULL)
		ft_strdel(&no);
	if (np && np != NULL)
		ft_strdel(&np);
	return (0);
}

int			cd_old(char **cmd, char opt[1])
{
	char	*np;
	char	*op;

	np = NULL;
	op = NULL;
	if ((np = ft_search_and_r("OLDPWD=", np)) == NULL)
		return (-1); // error OLDPWD not set
	if (chdir(np) == -1)
		return (-1); // cant reach OLDPWD
	ft_strdel(&np);
	np = getcwd(np, -1);
	if ((op = ft_search_and_r("PWD=", op)) == NULL)
		op = NULL;
	if (ft_search_and_c("OLDPWD=", op, "OLDPWD=") == NULL)
		d->env = add_new(d->env, op = ft_concat(op, "OLDPWD="), 0, 0);
	if (ft_search_and_c("PWD=", np, "PWD=") == NULL)
		d->env = add_new(d->env, np = ft_concat(np, "PWD="), 0, 0);
	if (np && np != NULL)
		ft_strdel(&np);
	if (op && op != NULL)
		ft_strdel(&op);
	np = getcwd(np, MAXPATHLEN);
	ft_putendl(np);
	ft_strdel(&np);
	return (0);
}

int			go_to(char *rp, char opt[1])
{
	char	*np;
	char	*op;

	np = NULL;
	op = NULL;
//	ft_putendl(rp);
	// // if (open(rp) == -1)
	// // 	return (-1);
	// if ((fchdir(open(rp, O_RDONLY))) == -1)
	// 	return (-1);
	if (chdir(rp) == -1)
		return (-1); // error cant acces to rp
	np = getcwd(np, -1);
	if ((op = ft_search_and_r("PWD=", op)) == NULL)
		op = NULL;
	if (!op)
		ft_search_and_c("OLDPWD=", op, "OLDPWD=");
	else if (op && (ft_search_and_c("OLDPWD=", op, "OLDPWD=")) == NULL)
		d->env = add_new(d->env, op = ft_concat(op, "OLDPWD="), 0, 0);
	if (np && ft_search_and_c("PWD=", np, "PWD=") == NULL)
		d->env = add_new(d->env, np = ft_concat(np, "PWD="), 0, 0);
	ft_strdel(&np);
	ft_strdel(&op);
	return (0);
}

int			get_opt_cd(char **s, char opt[1]) // int get_opt(char **s, char *opt, char *ref) // tools
{
	int		i;
	int		ii;

	i = 1;
	opt[0] = '\0';
	while (s && s[i])
	{
		ii = 1;
		if (s[i] && s[i][0] && s[i][0] == '-' && s[i][ii])
			while (s[i][ii])
			{
				if (s[i][ii] == 'L' || s[i][ii] == 'P')
					opt[0] = s[i][ii];
				else
					return (-1); // error on option
				ii++;
			}
		i++;
	}
	return (0);
}

char	**del_and_ajust_tab(char **s, int i) // tools
{
	int	t;

	if (s[i + 1] && s[i + 1] != NULL)
	{
		t = i + 1;
		ft_strdel(&s[i]);
		while (s && s[t])
		{
			s[i] = s[t];
			i++;
			t++;
		}
		s[i] = NULL;
		return (s);
	}
	else
		ft_strdel(&s[i]);
	return (s);
}

int		clear_opt(char **s) // tools
{
	int		i;
	char	*t;

	i = 0;
	while (s && s[i])
	{
		if (s[i] && s[i][0] && s[i][0] == '-' && s[i][1] && s[i][1] != '\0')
		{
			if ((s = del_and_ajust_tab(s, i)) == NULL)
				return (-1);
			else
				return (clear_opt(s));
		}
		i++;
	}
	return (0);
}

char		*fill_npwd(char *p, char *np, int i, char **cmd)
{
	int		a;
	int		k;

	a = 0;
	while (a < i)
	{
		np[a] = p[a];
		a++;
	}
	i = 0;
	k = a;
	while (p && cmd[1][i] && p[a++] == cmd[1][i])
		i++;
	i = 0;
	while (cmd[2][i])
		np[k++] = cmd[2][i++];
	while (p && p[a])
	{
		np[k] = p[a++];
		np[++k] = '\0';
	}
	ft_strdel(&p);
	return (np);
}

char		*change_d(char *p, char **c, int i, int u)
{
	char	*np;
	int		o;

	if ((np = (char *)malloc(sizeof(char) *
		(ft_strlen(p) + ft_strlen(c[2]) - ft_strlen(c[1])))) == NULL)
		return (NULL);
	while (p && p[i])
	{
		u = 0;
		if (p[i] == c[1][0])
		{
			o = i;
			while (c[1][u] && c[1][u] == p[i])
			{
				i++;
				u++;
			}	
			if (c[1][u] == '\0')
				return (fill_npwd(p, np, o, c));
			i = o;
		}
		i++;
	}
	return (p);
}

int			ft_strin(char *s1, char *s2) // tools
{
	int		i;
	int		a;

	i = 0;
	while (s1 && s1[i])
	{
		a = 0;
		if (s1[i] == s2[a])
		{
			while (s1[i] == s2[a])
			{
				i++;
				a++;
			}
			if (!s2[a])
				return (0);
		}
		i++;
	}
	return (1);
}

int			cd_to(char **cmd, char opt[1])
{
	char	*pwd;

//	pwd = getcwd(pwd, MAXPATHLEN);
	if ((pwd = ft_search_and_r("PWD=", pwd)) == NULL)
		pwd = getcwd(pwd, -1);
	if (cmd[2] && ft_strin(pwd, cmd[2]) == 0)
	{
		// pwd ou old >
		if ((pwd = change_d(pwd, cmd, 0, 0)) == NULL)
			return (-1);
		return (go_to(pwd, opt));
	}
	else
	{
		ft_strdel(&pwd);
		return (go_to(cmd[1], opt));
	}
	return (go_to(cmd[1], opt));
}

// char	**know_path(char **cmd)
// {
// 	char	pwd[MAXPATHLEN];
// 	int		i;
// 	int		a;

// 	a = 0;
// 	i = 0;
// 	getcwd(pwd, MAXPATHLEN);
// 	while (pwd[i])
// 		i++;
// 	pwd[i++] = '/';
// 	while (cmd[1] && cmd[1][a])
// 	{
// 		pwd[i] = cmd[1][a++];
// 		pwd[++i] = '\0';
// 	}
// 	ft_putendl(pwd);
// 	return (cmd);
// }

int			ft_cd(char **cmd)
{
	char	opt[1];
	char	link[MAXPATHLEN];
	DIR		*dirp;
	struct	dirent	*dd;
	// pas compris les options, je verrais ca plus tard -L -P a faire un truc du genre vire les .. et les / 
	if (get_opt_cd(cmd, opt) == -1 || clear_opt(cmd) == -1)
		return (-1);
	// if (cmd[1])
	// {
	// 	cmd = know_path(cmd);
	// 	return (0);
	// }
	// check sur absolute et relative path, puis check sur les link
	// trouver un solution pour eviter de faire appel a readlink
	if (cmd[1])
	{
		dirp = opendir(".");

	// else
	// 	dirp = opendir(".");
	while ((dd = readdir(dirp)) != NULL)
	{
			if (dd->d_type == DT_LNK && ft_memcmp(dd->d_name, cmd[1], ft_strlen(cmd[1])) == 0)
			{
				ft_putendl(dd->d_name);
				ft_putendl("GET LINK");
				ft_bzero(link, MAXPATHLEN);
				link[readlink(dd->d_name, link, MAXPATHLEN)] = '\0';
				if (link[0])
					ft_putendl(link);
			}
	}
		closedir(dirp);
	}
	if (!cmd[1])
		return (cd_home(cmd, opt));
	else if (!cmd[2] && cmd[1] && ft_memcmp(cmd[1], "-", 2) == 0)
		return (cd_old(cmd, opt));
	else if (cmd[1] && cmd[2] && cmd[3])
		return (-1);//cd: too many argument
	return (cd_to(cmd, opt));
}
