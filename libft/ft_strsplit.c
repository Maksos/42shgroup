/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/30 14:36:59 by maastie           #+#    #+#             */
/*   Updated: 2015/05/04 18:08:09 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			ft_wlen(char const *s, char c, int i)
{
	int		k;
	char	l;

	k = 0;
	while ((s[i] && s[i] != '\0') && s[i] != c)
	{
		if (s[i] == '\"' || s[i] == '\'')
		{
			l = s[i];
			i++;
			k++;
			while (s[i] && (s[i] != '\0' && s[i] != l))
			{
				i++;
				k++;
			}
		}
		if (s[i])
			i++;
		if (s[k])
			k++;
	}
	return (k);
}

char		**ft_fill(char **ret, char const *s, char c, int r)
{
	int		i;

	i = 0;
	r = 0;
	while (s && (s[i] && s[i] != '\0'))
	{
		while ((s[i] && s[i] != '\0') && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			ret[r] = ft_strsub(s, i, ft_wlen(s, c, i));
			ret[++r] = NULL;
			i = ft_wlen(s, c, i) + i;
		}
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		w;
	char	**ret;

	i = 0;
	w = 0;
	ret = NULL;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && (s[i] != c && s[i] != '\0'))
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	if (w == 0 || (ret = (char **)malloc(sizeof(char *) * (w + 2))) == NULL)
		return (ret);
	return (ft_fill(ret, s, c, (w + 1)));
}
