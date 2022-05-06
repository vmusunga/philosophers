/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:45 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/06 15:03:29 by vic              ###   ########.fr       */
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

void	*life(void *x)			///DATA ACCESS ATTEMPT CRASHES
{
	t_philo *philo;
	// t_data *data;

	philo = (t_philo *)x;
	// data = philo->data;
	printf("\nLIFE %d\n", philo->id);

	printf("\nleft : %d\n", philo->left_fork);
	printf("right : %d\n", philo->right_fork);
	printf("last meal : %lu\n", philo->last_meal);
	// printf("\nDATA TEST : %lu\n", philo->data->start);

	/// check_alive

	/// grab_fork

	/// sleep tts
	usleep(600);
	
	/// think

	return (NULL);
}
