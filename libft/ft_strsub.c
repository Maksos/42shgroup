/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 14:12:26 by maastie           #+#    #+#             */
/*   Updated: 2015/05/13 13:02:44 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	t;

	i = 0;
	if (s != NULL && len >= i)
	{
		t = ft_strlen((char*)s);
		if (t < len || start > t || (t < start + len))
			return (NULL);
		str = (char *)malloc(sizeof(char *) * len + 1);
		if (!str)
			return (NULL);
		ft_strncpy((char *)str, (char *)s + start, len);
		return (str);
	}
	return (NULL);
}
