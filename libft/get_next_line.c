/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:41:13 by maastie           #+#    #+#             */
/*   Updated: 2016/02/18 13:36:39 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include "./includes/libft.h"

char			*get_line(char **line, char *r)
{
	int			s;
	char		*k;

	k = r;
	if ((k = ft_strchr(r, '\n')))
	{
		*k = '\0';
		s = ft_strlen(r);
		*k = '\n';
		*line = ft_strsub(r, 0, s);
		return (r + s);
	}
	*line = ft_strdup(r);
	return (r + ft_strlen(r));
}

int				hid_line(char **r, char *b, char **l)
{
	if ((*r = ft_strchr(b, '\n')))
	{
		*r = ft_strsub(b, (ft_strlen(b) - ft_strlen(*r)), ft_strlen(*r)) + 1;
		if (*l)
			*l = ft_strjoin(*l, ft_strsub(b, 0, ft_strlen(b)
				- ft_strlen(*r) - 1));
		else
			*l = ft_strdup(ft_strsub(b, 0, ft_strlen(b) - ft_strlen(*r) - 1));
		return (1);
	}
	if (*l)
		*l = ft_strjoin(*l, b);
	else
		*l = ft_strdup(b);
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char *r[255];
	int			ret;
	char		buff[BUFF_SIZE];

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (r[fd])
	{
		r[fd] = get_line(line, r[fd]);
		if (*r[fd] == '\n')
		{
			r[fd]++;
			return (1);
		}
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((hid_line(&r[fd], buff, line)) == 1)
			return (1);
	}
	return (ret = (ret == 0) ? 0 : -1);
}
