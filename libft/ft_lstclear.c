/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:24:43 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/22 14:55:38 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *buff;
	t_list *ciao;

	if ((!(*lst)) || (!(*del)) || (!lst))
		return ;
	buff = *lst;
	while (buff != 0)
	{
		(*del)(buff->content);
		ciao = buff;
		buff = buff->next;
		free(ciao);
	}
	*lst = 0;
}
