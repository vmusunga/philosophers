/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/17 16:53:34 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp(t_philo *philo, char x)
{
	unsigned long start;
	start = philo->data->start;
	if (x == 'l')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "has taken his left fork");
	if (x == 'r')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "has taken his right fork");
	if (x == 'e')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "is eating");
	if (x == 's')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "is sleeping");
	if (x == 't')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "is thinking");
	if (x == 'd')
		printf("%ld %d %s\n", timediff(start), philo->id + 1, "died");
}

int	pepsi(t_data *data) //REDO
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (i < data->philo_nb)
	{
		printf("TAMERE\n");
		if (data->philo[i].is_alive)
		{
			if (timediff(data->philo[i].last_meal) >= data->ttd)
			{
				data->philo[i].is_alive = 0;
				error("GAME OVER");
			}
		}
		if (data->philo->meals == data->meals_nb)
			count++;
		if (count == data->philo_nb)
			error("YOU WIN");
		i++;
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork[philo->left_fork]))	///FORKS
		error("left fork error");
	timestamp(philo, 'r');
	if (pthread_mutex_lock(&philo->data->fork[philo->right_fork]))
		error("left fork error");
	timestamp(philo, 'l');

	timestamp(philo, 'e');
	philo->last_meal = current_time();						/// EATING
	usleep(philo->data->tte);
	philo->meals++;
	
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->fork[philo->left_fork]);
	return ;
}

void	ft_sleep(t_philo *philo)
{
	timestamp(philo, 's');
	usleep(philo->data->tts);
	return ;
}

void	*life(void *x)			///DATA ACCESS ATTEMPT CRASHES
{
	t_philo *philo;

	philo = (t_philo *)x;
	if (philo->id % 2)
		usleep(15000);
	while (philo->is_alive)
	{
		eat(philo);
		ft_sleep(philo);
		timestamp(philo, 't');
	}
	return (NULL);
}



	// data = philo->data;
	// printf("\nLIFE %d\n", philo->id);

	// printf("\nleft : %d\n", philo->left_fork);
	// printf("right : %d\n", philo->right_fork);
	// printf("last meal : %lu\n", philo->last_meal);
	// printf("\nDATA TEST : %lu\n", philo->data->start);