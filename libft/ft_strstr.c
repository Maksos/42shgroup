/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 17:51:49 by maastie           #+#    #+#             */
/*   Updated: 2015/04/22 17:52:54 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	return (ft_strnstr(s1, s2, ft_strlen(s1)));
}
