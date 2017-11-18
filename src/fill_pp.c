/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:26:43 by maastie           #+#    #+#             */
/*   Updated: 2017/09/27 19:26:43 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_42sh.h"

// sert a rien faut faire un tri des | et apr2s faire le reste

// int			fill_ope(char c)
// {
// }

// int			fill_in_pp(t_dpp *l, char *s, int i)
// {
// 	char	c;
// 	int		m;

// 	m = 0;
// 	while (s && s[i])
// 	{
// 		while (s[i] == ' ' || s[i] == '\t')
// 			i++;
// 		if (s[i] == '\'' || s[i] == '"' || s[i] == '`')
// 		{
// 			c = s[i++];
// 			while (s && s[i])
// 				i++;
// 			m = m + 1;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int			ft_fill_do_pp(char *s, t_dpp *l)
// {
// 	if (fill_in_pp(l, s, 0) == -1)
// 		return (-1);
// 	return (0);
// }