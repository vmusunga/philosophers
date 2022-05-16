/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/16 15:59:25 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp(t_philo *philo, char x)
{
	if (x == 'l')
		printf("%ld %d %s\n", current_time(), philo->id, "has taken his left fork");
	if (x == 'r')
		printf("%ld %d %s\n", current_time(), philo->id, "has taken his right fork");
	if (x == 'e')
		printf("%ld %d %s\n", current_time(), philo->id, "is eating");
	if (x == 's')
		printf("%ld %d %s\n", current_time(), philo->id, "is sleeping");
	if (x == 't')
		printf("%ld %d %s\n", current_time(), philo->id, "is thinking");
	if (x == 'd')
		printf("%ld %d %s\n", current_time(), philo->id, "died");
}

int	pepsi(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		if (current_time() - data->philo[i].last_meal >= data->ttd)
		{
			timestamp(data->philo, 'd');
			data->philo->is_alive = 0;
			return(1);
		}
		i++;
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork[philo->left_fork]))
		error("left fork error");
	timestamp(philo, 'r');
	if (pthread_mutex_lock(&philo->data->fork[philo->right_fork]))
		error("left fork error");
	timestamp(philo, 'l');
	timestamp(philo, 'f');
	timestamp(philo, 'e');
	usleep(philo->data->tte);
	philo->last_meal = current_time();
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
		if (pepsi(philo->data))
			error("ISDED\n");
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