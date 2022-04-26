/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:16:46 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/22 16:38:29 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (((char*)dst) == ((char*)src))
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			((char*)dst)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dst);
}
