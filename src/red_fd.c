/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:04:50 by maastie           #+#    #+#             */
/*   Updated: 2017/10/03 18:04:50 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"
int		apply_red_fd(t_red *r);

int			ft_error_red(int e, int ret)
{
	e == 1 ? ft_putendl_fd("Error open in redirection", STDERR_FILENO) : e;
	return (ret);
}


int			ft_del_and_down(t_red *r, char **c, int i)
{
	int		e;

	e = i + 1;
	ft_strdel(&c[i]);
	c[i] = c[e];
	while (c && c[i])
	{
		i++;
		e++;
		c[i] = c[e];
	}
	c[i] = NULL;
	return (apply_red_fd(r));
//	return (do_red_fd(r, r->act));
}

int			get_fd(char *st, int s, int e, int i)
{
	char	*new;

	if (st[s] == '-' && (s + 1 == e))
		return (-3);
	if ((new = (char *)malloc(sizeof(char) * (e - s) + 2)) == NULL)
		return (-1);
	while (st && st[s] && s < e)
	{
		new[i] = st[s++];
		new[++i] = '\0';
	}
	i = 0;
	while (new && new[i] && ft_isdigit(new[i]) == 1)
		i++;
	if (new[i] == '\0')
		s = atoi(new);
	else
		s = open(new, O_CREAT | O_TRUNC | O_WRONLY, 0755);
	ft_strdel(&new);
	if (s == -1)
		return (ft_error_red(1, -1));
	return (s);
}

int		swap_fd(char *s, int e, int i)
{
	int		ffd;
	int		sfd;

	while (s && s[i])
	{
		if (s[i] == '>')
		{
			ffd = get_fd(s, e, i, 0);
			e = i + 2;
			sfd = get_fd(s, e, ft_strlen(s), 0);
			if (sfd == ffd)
				return (0);
			if (sfd == -3)
				return (close(ffd));
			else if (sfd == -1 || ffd == -1)
				return (-1);
			else
			{
				close(ffd);
				dup(sfd);
			}
			return (0);
		}
		i++;
	}
	return (0);
}

int		apply_red_fd(t_red *r)
{
	int	i;

	i = 0;
	while (r->cmd && r->cmd[i])
	{
		if (ft_strstr(r->cmd[i], ">&") != 0)
		{
			if (swap_fd(r->cmd[i], 0, 0) == -1)
				return (-1);
			return (ft_del_and_down(r, r->cmd, i));
		}
		i++;
	}
	return (0);
}

int		do_red_fd(t_red *r, char *act)
{
	int	rr;

	if (!r) // && non-built-in
		return (0);
	if (apply_red_fd(r) == -1)
		return (-1);
	if (!act)
		return (0);
	if (ft_memcmp(act, ">", 2) == 0)
		rr = r_red(r->cmd);
	else if (ft_memcmp(act, "<", 2) == 0)
		rr = l_red(r->cmd, 0);
	else if (ft_memcmp(act, ">>", 3) == 0)
		rr = rr_red(r->cmd);
	else if (ft_memcmp(act, "<<", 3) == 0)
		rr = ll_red(r);
	if (rr == 0)
		return (do_red_fd(r->nxt, r->act)); // del
	return (-1);
}

int		red_fd(t_red *r)
{
	// if (r->act)
	// 	return (do_red_fd(r->nxt, r->act));
	// else
	if (apply_red_fd(r) == 0)
		return (do_red_fd(r->nxt, r->act));
	return (-1);
}