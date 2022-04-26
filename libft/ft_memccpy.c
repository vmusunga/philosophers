/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 19:41:39 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/13 17:16:39 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)src)[i] != ((unsigned char)c))
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			i++;
		}
		else
		{
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
			return (&dst[i + 1]);
		}
	}
	return (NULL);
}
