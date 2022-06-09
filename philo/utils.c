/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/06/09 18:12:39 by vmusunga         ###   ########.fr       */
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

	diff = (current_time() - start);
	return (diff);
}

int	destroy(t_data *data)   //no leak without the returns
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_unlock(&data->fork[i]);
		if (pthread_mutex_destroy(&data->fork[i]))
			return (error("Mutex destroy5"));
		i++;
	}
	pthread_mutex_unlock(&data->death);
	if (pthread_mutex_destroy(&data->death))
		return (error("Mutex destroy1"));
	pthread_mutex_unlock(&data->writing);
	if (pthread_mutex_destroy(&data->writing))
		return (error("Mutex destroy2"));
	pthread_mutex_unlock(&data->meal_time);
	if (pthread_mutex_destroy(&data->meal_time))
		return (error("Mutex destroy3"));
	pthread_mutex_unlock(&data->meal_update);
	if (pthread_mutex_destroy(&data->meal_update))
		return (error("Mutex destroy4"));
	return (0);
}

int	game_over(t_philo *philo, int code)
{
	unsigned long	start;

	start = philo->data->start;
	pthread_mutex_lock(&philo->data->death);
	philo->data->dead = code;
	pthread_mutex_unlock(&philo->data->death);
	pthread_mutex_lock(&philo->data->writing);
	if (code == -1)
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "died");
	if (code == 1)
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "ate enough");
	return (0);
}

int	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	return (0);
}
