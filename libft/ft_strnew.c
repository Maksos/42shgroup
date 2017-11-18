/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:50:09 by maastie           #+#    #+#             */
/*   Updated: 2015/04/23 17:54:07 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	while (i <= size)
	{
		ret[i] = '\0';
		i++;
	}
	return (ret);
}
