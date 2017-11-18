/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/01 14:28:44 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 15:28:05 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_knowneg(int n)
{
	int		c;
	int		x;
	char	*r;

	x = 1;
	c = 0;
	if (n > 0)
		n = -n;
	while ((n / x) < -9)
	{
		c++;
		x = x * 10;
	}
	if ((r = (char *)malloc(sizeof(char) * c + 1)) == NULL)
		return (NULL);
	r[c + 1] = '\0';
	return (r);
}

char		*ft_itoa(int n)
{
	int		c;
	int		x;
	char	*r;

	if ((r = ft_knowneg(n)) == NULL)
		return (NULL);
	c = 0;
	x = 1;
	if (n < 0)
	{
		r[0] = '-';
		c = 1;
	}
	if (n > 0)
		n = -n;
	while ((n / x) < -9)
		x = x * 10;
	while (x > 0)
	{
		r[c] = '0' - (n / x);
		n = n % x;
		c++;
		x = x / 10;
	}
	return (r);
}
