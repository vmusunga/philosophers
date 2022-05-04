/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/04 14:48:51 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	timeset()
{
	unsigned long	time;
	struct timeval tmp;

	gettimeofday(&tmp, NULL);
	time = tmp.tv_sec + (tmp.tv_usec / 1000);
	return (time);
}

void	destroy(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

int	input_check(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(ft_atoi(av[i])))
			return (1);
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		error("Bruh.");
	return (0);
}

void	free_tab(char *str, char *str2)
{
	free(str2);
	free(str);
	return ;
}

void	free_tab2(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return ;
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_SUCCESS);
}
