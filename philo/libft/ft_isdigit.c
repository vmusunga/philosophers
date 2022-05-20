/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:31:58 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/20 14:10:48 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	isdigit_check(char *sth)
{
	int	i;

	i = 0;
	while (sth[i])
	{
		if (sth[i] < '0' && sth[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
