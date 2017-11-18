/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:58:19 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:16:37 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
					int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src;
		if (*(unsigned char *)src++ == (unsigned char)c)
			return ((unsigned char *)dst);
	}
	return (NULL);
}
