/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/04 16:08:26 by vic              ###   ########.fr       */
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

void	*life(t_data *data)
{
	printf("\nLIFE\n");
	/// grab_fork
	usleep(600);
	/// sleep tts

	/// think

	/// check_alive
	if (timediff(data->philo) >= (unsigned long)data->ttd * 1000)
	{
		usleep(1000);
		//timestamp(data->philo,'d');
	}
	// printf("%i, %i, %i, %i, %ld\n", data->philo_nb, data->ttd, data->tte, data->tts, data->philo->start.tv_sec);
	return (NULL);
}
