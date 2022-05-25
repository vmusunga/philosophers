/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:31:58 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/25 19:32:50 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		// printf("CHECK: %c\n", sth[i]);
		if (sth[i] < '0' && '9' < sth[i])
		{
			// printf("WTF\n");
			return (0);
		}
		i++;
	}
	return (1);
}
