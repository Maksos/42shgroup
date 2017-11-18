/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 14:22:52 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:07:20 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		c;
	size_t	r;

	i = 0;
	c = 0;
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (s[i] == '\0')
		return (ft_strsub(s, 0, 0));
	c = i;
	while (s && s[i])
		i++;
	i--;
	while (s && s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	r = i - c;
	return (ft_strsub(s, c, (r + 1)));
}
