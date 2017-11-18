/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 15:41:00 by maastie           #+#    #+#             */
/*   Updated: 2017/07/10 15:41:00 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

char		**add_new(char **tabl, char *s, int i, int k)
{
	char	**r;

	while (tabl && (tabl[i] && tabl[i][0]))
		i++;
	if ((r = (char **)ft_memalloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	// while (k != (i + 2))
	// 	r[k++] = NULL;
	// k = 0;
	while (tabl && tabl[k])
	{
		r[k] = ft_strdup(tabl[k]);
//		ft_strdel(&tabl[k]);
		r[++k] = NULL;
	}
	tabl = ft_free_tab(tabl);
	// if (tabl && tabl != NULL)
	// {
	// 	free(tabl);
	// 	tabl = NULL;
	// }
	r[k] = ft_strdup(s);
	r[++k] = NULL;
	return (r);
}

char		**cpy_tab(char **dst, char **src, int k)
{
	int		i;

	i = 0;
	while (src && src[i])
		i++;
	if (i == 0 || (dst = (char **)malloc(sizeof(char *) * (i + k))) == NULL)
		return (NULL);
	i = 0;
	while (src && src[i])
	{
		dst[i] = ft_strdup(src[i]);
		dst[++i] = NULL;
	}
	return (dst);
}


char		*ft_adchar(char *s, char c)
{
	int		i;
	char	*n;

	i = 0;
	if (s == NULL)
	{
		if ((s = (char *)malloc(sizeof(char) * 2)) == NULL)
			return (NULL);
		s[0] = c;
		s[1] = '\0';
		return (s);
	}
	if ((n = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2))) == NULL)
		return (NULL);
	while (s && s[i])
	{
		n[i] = s[i];
		i++;
	}
	n[i] = c;
	n[++i] = '\0';
	ft_strdel(&s);
	return (n);
}

// char		*ncpy(char *l, int s)
// {
// 	char	*r;
// 	int		i;

// 	i = ft_strlen(l) - s + 1;
// 	if ((r = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (l && l[s])
// 	{
// 		r[i] = '\0';
// 		r[i] = l[s];
// 		i++;
// 		r[i] = '\0';
// 		s++;
// 	}
// 	return (r);
// }
