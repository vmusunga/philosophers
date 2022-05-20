/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/20 15:08:14 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	current_time(void)
{
	unsigned long	time;
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	time = (tmp.tv_sec * 1000) + (tmp.tv_usec / 1000);
	return (time);
}

unsigned long	timediff(unsigned long start)
{
	unsigned long	diff;
	// printf("start: %ld -- current: %ld\n", start, current_time());
	diff = (current_time() - start);
	return (diff);
}

void	destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->fork[i]);
		if (data->philo)							/// in/out loop?
			free(data->philo);
		i++;
	}
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->writing);
	pthread_mutex_destroy(&data->meal_time);
	pthread_mutex_destroy(&data->meal_update);
	if (data)
		free(data);
	return ;
}

void	input_check(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!isdigit_check(av[i]))
			error("Only digits allowed");
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		error("Bruh.");
	return ;
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_SUCCESS);
}
