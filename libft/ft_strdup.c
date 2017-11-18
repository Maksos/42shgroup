/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 15:45:48 by maastie           #+#    #+#             */
/*   Updated: 2015/05/13 13:32:42 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*new;

	i = 0;
	if (ft_strlen(s1) == 0)
		return (NULL);
	else if ((new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	if (new)
	{
		while (s1[i] && s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
