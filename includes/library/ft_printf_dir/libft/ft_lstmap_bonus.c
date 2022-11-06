/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaou <kaou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:31:31 by kaou              #+#    #+#             */
/*   Updated: 2021/10/24 22:06:46 by kaou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*last;

	if (!lst || !f || !(*f))
		return (NULL);
	first = ft_lstnew((*f)(lst->content));
	if (!first)
		return (NULL);
	last = first;
	lst = lst->next;
	while (lst)
	{
		last->next = ft_lstnew((*f)(lst->content));
		if (!(last->next))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		last = last->next;
		lst = lst->next;
	}
	return (first);
}
