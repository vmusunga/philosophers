/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:41:46 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/13 14:54:32 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t i;
	size_t x;

	x = 0;
	i = 0;
	if (needle[0] == '\0')
		return (((char*)haystack));
	while (haystack[i])
	{
		x = 0;
		while (haystack[i + x] == needle[x] && (x + i < size))
		{
			if (needle[x + 1] == '\0')
				return (&((char*)haystack)[i]);
			x++;
		}
		i++;
	}
	return (0);
}
