/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/13 16:12:29 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	timestamp(t_philo *philo, char x)
{
	if (x == 'f')
		printf("%ld %d %s", current_time(), philo->id, "has taken a fork");
	if (x == 'e')
		printf("%ld %d %s", current_time(), philo->id, "is eating");
	if (x == 's')
		printf("%ld %d %s", current_time(), philo->id, "is sleeping");
	if (x == 't')
		printf("%ld %d %s", current_time(), philo->id, "is thinking");
	if (x == 'd')
		printf("%ld %d %s", current_time(), philo->id, "died");
}

int	pepsi(t_philo *philo)
{
	if (current_time() - philo->last_meal >= philo->data->ttd)
	{
		philo->is_alive = 0;
		timestamp(philo, 'd');
		return(1);
	}
	return (0);
}

void	eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->data->fork[philo->left_fork]))
		timestamp(philo, 'f');
	if (pthread_mutex_lock(&philo->data->fork[philo->right_fork]))
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
	usleep(philo->data->tts);
	timestamp(philo, 's');
	return ;
}

void	*life(void *x)			///DATA ACCESS ATTEMPT CRASHES
{
	t_philo *philo;
	// t_data *data;

	philo = (t_philo *)x;
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