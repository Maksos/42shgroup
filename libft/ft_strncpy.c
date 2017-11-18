/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:26:22 by maastie           #+#    #+#             */
/*   Updated: 2015/05/13 12:58:46 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		else if (src[i] == '\0')
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
	}
	dst[i] = 0;
	return (dst);
}
