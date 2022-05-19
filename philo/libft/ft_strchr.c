/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:34:21 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/15 10:38:45 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		while (s[i])
			i++;
		return (&((char *)s)[i]);
	}
	while (s[i] != ((char)c) && s[i])
		i++;
	if (s[i] == ((char)c))
		return (&((char *)s)[i]);
	return (0);
}
