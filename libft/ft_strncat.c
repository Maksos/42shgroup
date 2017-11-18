/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:56:46 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 13:55:44 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	char	*t;

	t = s1;
	while (*t)
		t++;
	while (n > 0 && *s2)
	{
		*t = *s2;
		t++;
		s2++;
		n--;
	}
	*t = '\0';
	return (s1);
}
