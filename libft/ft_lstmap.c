/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maastie <maastie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/04 19:42:00 by maastie           #+#    #+#             */
/*   Updated: 2015/05/05 14:35:24 by maastie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/list.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	tmp = f(lst);
	new = tmp;
	if (new == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		if ((tmp->next = f(lst)) == NULL)
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
