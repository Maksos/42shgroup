/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:55:24 by maastie           #+#    #+#             */
/*   Updated: 2015/04/30 18:10:28 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	int		res;

	l1 = ft_strlen(s1) + 1;
	l2 = ft_strlen(s2) + 1;
	l1 = (l1 <= l2) ? l1 : l2;
	res = ft_memcmp(s1, s2, l1);
	return (res);
}
