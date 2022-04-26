/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:38:51 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/22 14:42:46 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srclen;

	if ((!(dst)) || (!(src)))
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	if (dst == 0 || size == 0)
		return (srclen);
	while ((i < size - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
