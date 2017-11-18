/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lred.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:25:27 by maastie           #+#    #+#             */
/*   Updated: 2017/10/06 16:25:28 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int		l_red(char **cmd, int i)
{
	int		fd;

	close(d->pdes[0]);
	if ((fd = open(cmd[i], O_RDONLY)) == -1)
		return (-1);
	if (dup2(fd, d->pdes[0]) == -1)
		return (-1);
	if (cmd[i + 1] && cmd[i + 1] != NULL)
		return (l_red(cmd, ++i));
	return (0);
}

void		prompt_ll_red(void)
{
	int		i;

	i = 0;
	while (i < d->ph)
	{
		ft_putstr_fd("pipe ", d->pdes[0]);
		i++;	
	}
	ft_putstr_fd("heredoc>", d->pdes[0]);
}

int		ll_read(int fd, char *mc)
{
	char	r[MAXPATHLEN];

	default_term();
	prompt_ll_red();
	ft_bzero(r, MAXPATHLEN);
	while (read(d->pdes[0], r, MAXPATHLEN) > 0)
	{
		if (ft_memcmp(r, mc, (ft_strlen(r) - 1)) == 0
			&& (r[0] && r[0] != '\n'))
			break ;
		else
			ft_putstr_fd(r, fd);
		ft_bzero(r, MAXPATHLEN);
		prompt_ll_red();
	}
	close(fd);
	init_termcap(d->pdes[0]);
	return (0);
}

int		ll_red(t_red *r)
{
	int	fd;

	if ((fd = (open("/tmp/heredoc", O_CREAT | O_TRUNC | O_RDWR, 0755))) == -1)
		return (-1);
	if (ll_read(fd, r->cmd[0]) == -1)
		return (-1);
	if ((fd = (open("/tmp/heredoc", O_RDONLY))) == -1)
		return (-1);
	if (dup2(fd, d->pdes[0]) == -1)
		return (-1);
 	return (0);
}