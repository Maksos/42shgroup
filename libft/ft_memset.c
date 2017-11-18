/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:09:36 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:12:11 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*k;

	if (len == 0)
		return (b);
	k = (unsigned char *)b;
	while (len--)
	{
		*k = (unsigned char)c;
		if (len)
			k++;
	}
	return (b);
}
