/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 16:28:21 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 13:31:04 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int		i;
	int		k;

	k = 0;
	i = 0;
	while (s1 && s1[i])
		i++;
	while (s2 && (s2[k] && s2[k] != '\0'))
	{
		s1[i] = s2[k];
		i++;
		k++;
	}
	s1[i] = '\0';
	return (s1);
}
