/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:16:33 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:12:54 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s1;
	char	*s2;

	if (n == 0 || dst == src)
		return (dst);
	s1 = (char *)dst;
	s2 = (char *)src;
	while (--n)
		*s1++ = *s2++;
	*s1 = *s2;
	return (s1);
}
