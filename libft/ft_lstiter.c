/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 19:38:10 by maastie           #+#    #+#             */
/*   Updated: 2015/05/05 14:31:58 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/list.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	f(lst);
	while (lst->next != NULL)
	{
		lst = lst->next;
		f(lst);
	}
}
