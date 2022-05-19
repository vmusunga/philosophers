/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:28:36 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/18 14:58:01 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if ((!lst) || (!(*f)))
		return (NULL);
	if (!(new = ft_lstnew((*f)(lst->content))))
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst != 0)
	{
		if (!(new->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&start, (*del));
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
