/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 21:14:54 by maastie           #+#    #+#             */
/*   Updated: 2017/09/07 21:14:55 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

int				ft_error(int error, int ret)
{
	error == 1 ? ft_putendl_fd("Error : Launcher", STDERR_FILENO) : error;
	error == 2 ? ft_putendl_fd("Error : Malloc", STDERR_FILENO) : error;
	error == 3 ? ft_putendl_fd("Error : Initiation data", STDERR_FILENO) :
	error;
	error == 4 ? ft_putendl_fd("Error : Termcaps", STDERR_FILENO) : error;
	error == 5 ? ft_putendl_fd("Error : Init termcaps", STDERR_FILENO) : error;
	error == 6 ? ft_putendl_fd("Error : Reading termcap", STDERR_FILENO) :
	error;
	error == 7 ? ft_putendl_fd("Error : Malloc struct", STDERR_FILENO) : error;
	error == 7 ? ft_putendl_fd("Error : Malloc struct", STDERR_FILENO) : error;
	return (ret);
}

