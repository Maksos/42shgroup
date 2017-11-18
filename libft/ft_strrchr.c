/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:49:45 by maastie           #+#    #+#             */
/*   Updated: 2015/04/22 17:51:29 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *sr;

	sr = (char *)s + ft_strlen(s);
	while (*sr != c)
	{
		if (sr == s)
			return (NULL);
		sr--;
	}
	return (sr);
}
