/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 14:16:57 by maastie           #+#    #+#             */
/*   Updated: 2015/05/13 13:37:46 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_allow(char *str, char const *s1, char const *s2)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 != NULL && s2 != NULL)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1) +
					ft_strlen((char *)s2)) + 1);
		if (!str)
			return (NULL);
		str = ft_allow(str, s1, s2);
		free((void *)s1);
		free((void *)s2);
		return (str);
	}
	return (NULL);
}
