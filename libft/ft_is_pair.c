/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_pair.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/05 16:06:10 by maastie           #+#    #+#             */
/*   Updated: 2015/05/05 16:14:11 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_is_pair(int c)
{
	int	i;

	if (c < 0)
		c = -c;
	if (c > 9)
	{
		i = c % 10;
		if (i == 8 || i == 6 || i == 4 || i == 2 || i == 0)
			return (1);
		return (0);
	}
	if (c == 8 || c == 6 || c == 4 || c == 2 || c == 0)
		return (1);
	return (0);
}