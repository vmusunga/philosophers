/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:01 by vic               #+#    #+#             */
/*   Updated: 2022/05/06 15:11:39 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, char **av)
{
	int i;

	i = 0;
	data->philo_nb = ft_atoi(av[1]);
	data->ttd = (ft_atoi(av[2]) * 1000);
	data->tte = (ft_atoi(av[3]) * 1000);
	data->tts = (ft_atoi(av[4]) * 1000);
	data->start = current_time();

	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philo)
		error("Malloc error");

	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->fork)
		error("Malloc error");
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
}

void	philo_init(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		data->philo[i].id = i;
		data->philo[i].is_alive = 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philo_nb;
		data->philo[i].last_meal = data->start;
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, life, &data->philo[i])) // ATTENTION
			error("Thread error");
		i++;
	}
	i = 0;
	while (i < data->philo_nb)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL))
			error("Join thread error");
		i++;
	}
	return ;
}