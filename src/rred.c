/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rred.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:25:32 by maastie           #+#    #+#             */
/*   Updated: 2017/10/06 16:25:32 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

void		ft_error_rred(char *e)
{
//	struct stat *buf;
//
//	if ((buf = (struct stat *)malloc(sizeof(struct stat))) == NULL)
//		return ;
	if (access(e, F_OK) == -1)
	{
		ft_putstr_fd("Error : no such file or directory : ", STDERR_FILENO);
		ft_putendl_fd(e, STDERR_FILENO);
	}
	else
	{
		ft_putstr_fd("Error : permission denied: ", STDERR_FILENO);
		ft_putendl_fd(e, STDERR_FILENO);
	}
//	free(buf);
}

int		r_red(char **cmd)
{
	int		fd;

	if (!cmd)
		return (0);
	close(d->pdes[1]); //stdout
	if ((fd = open(cmd[0], O_CREAT | O_TRUNC | O_WRONLY, 0755)) == -1)
	{
		dup2(d->pdes[1], fd);
		ft_error_rred(cmd[0]);
		return (-1);
	}
	if (dup2(d->pdes[1], fd) == -1)
		return (-1);
	return (0);
}

int		rr_red(char **cmd)
{
	int		fd;

	if (!cmd)
		return (0);
	close(d->pdes[1]);
	if ((fd = open(cmd[0], O_APPEND | O_CREAT | O_WRONLY, 0755)) == -1)
	{
		ft_error_rred(cmd[0]);
		return (-1);
	}
	if (dup2(d->pdes[1], fd) == -1)
		return (-1);
	return (0);
}