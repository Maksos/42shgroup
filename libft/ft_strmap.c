/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 18:01:11 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:08:39 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ret;

	i = 0;
	while (s[i])
		i++;
	if ((ret = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
