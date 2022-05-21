/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/21 15:29:36 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp(t_philo *philo, char x)
{
	unsigned long start;
	int dead;

	start = philo->data->start;
	pthread_mutex_lock(&philo->data->writing);
	pthread_mutex_lock(&philo->data->death);
	dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->death);
	if (!dead)
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

int	pepsi(t_data *data)
{
	int i;
	int count;

	count = 0;

	while (!data->dead)
	{
		i = 0;
		while (i < data->philo_nb)
		{
			pthread_mutex_lock(&data->death);
			if (timediff(data->philo[i].last_meal) > data->ttd)
			{
				game_over(data->philo);
				// data->dead = -1;
				// error("GAME OVER");
			}
			pthread_mutex_unlock(&data->death);
			pthread_mutex_lock(&data->meal_update);
			if (data->meals_nb != -1 && data->philo[i].meals >= data->meals_nb)
			{
				// if (count == data->philo_nb - 1)
				count++;
			}
			pthread_mutex_unlock(&data->meal_update);
			i++;
		}
		if (data->dead)
			break;
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

	ft_sleep(philo, philo->data->tte);

	pthread_mutex_lock(&philo->data->meal_update);
	philo->meals++;
	pthread_mutex_unlock(&philo->data->meal_update);
	
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->right_fork]);
	usleep(100);
	return ;
}

void	ft_sleep(t_philo *philo, unsigned long time)								/// stops sleeping too early?
{
	unsigned long start;
	int dead;

	start = current_time();
	pthread_mutex_lock(&philo->data->death);
	dead = philo->data->dead;
	pthread_mutex_unlock(&philo->data->death);
	while(!dead)
	{
		// printf("%d	Sleeping : %ld	tts: %ld\n", philo->id, timediff(now), time);
		if (timediff(start) >= time)
			break;
		usleep(50);
	}
	return ;
}

void	*life(void *x)
{
	t_philo *philo;
	int dead;

	philo = (t_philo *)x;
	if (philo->id % 2)
		usleep(15000);
	// while (!philo->data->dead)
	dead = 0;
	while (!dead)
	{
		eat(philo);
		pthread_mutex_unlock(&philo->data->death);
		dead = philo->data->dead;
		pthread_mutex_unlock(&philo->data->death);
		if (dead)
			break;
		timestamp(philo, 's');
		ft_sleep(philo, philo->data->tts);
		timestamp(philo, 't');
		usleep(500);
	}
	return (NULL);
}
