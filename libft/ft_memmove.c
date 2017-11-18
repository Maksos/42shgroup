/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:18:51 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:12:25 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*c1;
	char	*c2;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (dst > src)
	{
		if (len == 0 || dst == src)
			return (dst);
		c1 = (char *)dst;
		c2 = (char *)src;
		while (len--)
			c1[len] = c2[len];
	}
	return (dst);
}
