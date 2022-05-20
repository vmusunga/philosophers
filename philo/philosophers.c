/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/20 15:13:31 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp(t_philo *philo, char x)
{
	unsigned long start;
	start = philo->data->start;
	pthread_mutex_lock(&philo->data->writing);
	if (!philo->data->dead)
	{
		if (x == 'l')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "has taken a fork");
		if (x == 'r')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "has taken a fork");
		if (x == 'e')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "is eating");
		if (x == 's')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "is sleeping");
		if (x == 't')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "is thinking");
		if (x == 'd')
			printf("%ld %d %s\n", timediff(start), philo->id + 1, "died");
	}
	pthread_mutex_unlock(&philo->data->writing);
	return ;
}

int	pepsi(t_data *data) //REDO
{
	int i;
	int count;

	count = 0;

	while (!data->dead)
	{
		i = 0;
		while (i < data->philo_nb)
		{
			// printf("%d	TTD: %ld -- TIMEDIFF: %ld\n", data->philo[i].id, data->ttd, timediff(data->philo[i].last_meal));
			pthread_mutex_lock(&data->death);
			if (timediff(data->philo[i].last_meal) >= data->ttd)
			{
				timestamp(data->philo, 'x');
				data->dead = -1;
				error("GAME OVER");
			}
			pthread_mutex_unlock(&data->death);
			i++;
		}
		if (data->philo->meals == data->meals_nb)
			count++;
		if (count == data->philo_nb)
		{
			pthread_mutex_lock(&data->death);
			data->dead = 1;
			pthread_mutex_unlock(&data->death);
			error("YOU WIN");
		}
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork[philo->left_fork]))	/// FORKS
		error("left fork error");
	timestamp(philo, 'r');
	if (pthread_mutex_lock(&philo->data->fork[philo->right_fork]))
		error("left fork error");
	timestamp(philo, 'l');

	timestamp(philo, 'e');											/// EATING
	pthread_mutex_lock(&philo->data->meal_time);
	philo->last_meal = current_time();
	pthread_mutex_unlock(&philo->data->meal_time);

	usleep(philo->data->tte);

	pthread_mutex_lock(&philo->data->meal_update);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->meal_update);
	
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	usleep(100);
	return ;
}

void	ft_sleep(t_philo *philo, unsigned long time)
{
	timestamp(philo, 's');
	usleep(time);
	return ;
}

void	*life(void *x)
{
	t_philo *philo;

	philo = (t_philo *)x;
	if (philo->id % 2)
		usleep(15000);
	while (!philo->data->dead)
	{
		eat(philo);
		ft_sleep(philo, philo->data->tts);
		timestamp(philo, 't');
		usleep(500);
	}
	return (NULL);
}
