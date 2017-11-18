/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 18:01:16 by maastie           #+#    #+#             */
/*   Updated: 2015/04/30 14:11:20 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l;
	size_t	l2;
	int		res;

	l = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l = (l <= l2) ? l + 1 : l2 + 1;
	l = (l <= n) ? l : n;
	res = ft_memcmp(s1, s2, l);
	return (res);
}
