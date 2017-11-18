/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:13:14 by maastie           #+#    #+#             */
/*   Updated: 2015/04/22 16:15:41 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (src[i] == '\0')
		dst[i] = src[i];
	else
		dst[i] = '\0';
	return (dst);
}
