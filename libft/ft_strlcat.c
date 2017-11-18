/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:38:32 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:10:13 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ret;
	char	*s;
	size_t	len;

	ret = (char *)ft_memchr(dst, '\0', size);
	if (ret == NULL)
		return (size + ft_strlen(src));
	s = (char *)src;
	len = (size_t)(ret - dst) + ft_strlen(s);
	while ((size_t)(ret - dst) < size - 1 && *s != '\0')
	{
		*ret = *s;
		ret++;
		s++;
	}
	*ret = '\0';
	return (len);
}
