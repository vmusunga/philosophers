/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:01 by vic               #+#    #+#             */
/*   Updated: 2022/05/25 18:31:31 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_struct(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->philo_nb = ft_atoi(av[1]);
	data->ttd = (ft_atoi(av[2]));
	data->tte = (ft_atoi(av[3]));
	data->tts = (ft_atoi(av[4]));
	data->dead = 0;
	data->meals_nb = -1;
	if (av[5])
		data->meals_nb = ft_atoi(av[5]);
	data->start = current_time();
	data->philo = malloc(sizeof(t_philo) * data->philo_nb);
	if (!data->philo)
		return (error("Malloc error"));
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->fork)
		return (error("Malloc error"));
	while (i < data->philo_nb)
	{
		pthread_mutex_init(&data->fork[i], NULL);
		i++;
	}
	return (1);
}

int	philo_init(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_nb)
	{
		data->philo[i].id = i;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philo_nb;
		data->philo[i].last_meal = data->start;
		data->philo[i].meals = 0;
		data->philo[i].data = data;
	}
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, life, &data->philo[i]))
			return (error("Thread error"));
	}
	if (!pepsi(data))
		return (0);
	i = 0;
	while (i < data->philo_nb)
		if (pthread_join(data->philo[i++].philo_thread, NULL))
			return (error("Join thread error"));
	return (1);
}
