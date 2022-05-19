/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:42:20 by vmusunga          #+#    #+#             */
/*   Updated: 2021/01/18 11:39:16 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intcount(int n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_revstr(char *str)
{
	char	buff;
	int		i;
	int		len;
	int		x;

	len = 0;
	i = 0;
	while (str[len])
		len++;
	x = len - 1;
	while (i < x)
	{
		buff = str[i];
		str[i] = str[x];
		str[x] = buff;
		i++;
		x--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int				i;
	unsigned int	nb;
	char			*str;
	int				count;

	nb = n;
	i = 0;
	count = ft_intcount(n);
	if (n == 0)
		count = 1;
	if (n < 0)
		nb = -n;
	if (!(str = malloc(sizeof(char) * (count + (n < 0 ? 2 : 1)))))
		return (NULL);
	while (i < count)
	{
		str[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_revstr(str);
	return (str);
}
