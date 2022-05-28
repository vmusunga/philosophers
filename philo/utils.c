/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/28 15:14:10 by vmusunga         ###   ########.fr       */
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

int	destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_mutex_destroy(&data->fork[i]))
			error("Mutex destoroy5");
		i++;
	}
	if (pthread_mutex_destroy(&data->death))
		error("Mutex destroy1");
	if (pthread_mutex_destroy(&data->writing))
		error("Mutex destroy2");
	if (pthread_mutex_destroy(&data->meal_time))
		error("Mutex destroy3");
	if (pthread_mutex_destroy(&data->meal_update))
		error("Mutex destroy4");
	return (1);
}

int	game_over(t_philo *philo, int code)
{
	unsigned long	start;

	start = philo->data->start;
	pthread_mutex_lock(&philo->data->death);
	philo->data->dead = code;
	pthread_mutex_unlock(&philo->data->death);
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
