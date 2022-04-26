/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:23:20 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/15 16:47:34 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcmp(char const s1, char const *s2)
{
	int x;

	x = 0;
	while (s2[x] != '\0')
	{
		if (s1 == s2[x])
			return (1);
		x++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;
	size_t	len;
	size_t	x;
	char	*new;

	if ((!s1) || (!set))
		return (0);
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strcmp(s1[i], set) == 1)
		i++;
	while (ft_strcmp(s1[len - 1], set) == 1)
		len--;
	if (len > i)
		n = len - i;
	else
		n = len;
	if (!(new = malloc(sizeof(char) * (n + 1))))
		return (NULL);
	x = 0;
	while (x < n)
		new[x++] = s1[i++];
	new[x] = '\0';
	return (new);
}
