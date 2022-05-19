/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:40:10 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/13 17:38:35 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (s[len])
		len++;
	if (c == '\0')
		return (&((char *)s)[len]);
	while (len > 0)
	{
		if (s[len - 1] == ((char)c))
			return (&((char *)s)[len - 1]);
		len--;
	}
	return (0);
}
