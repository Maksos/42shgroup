/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 17:45:46 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:15:40 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;
	size_t	i;

	if ((ret = malloc(size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret[i] = 0;
		i++;
	}
	return (ret);
}
