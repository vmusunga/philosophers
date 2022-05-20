/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:01 by vic               #+#    #+#             */
/*   Updated: 2022/05/20 15:00:36 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, char **av)
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
			error("Thread error");
	}
	pepsi(data);
	i = 0;
	while (i < data->philo_nb)
		if (pthread_join(data->philo[i++].philo_thread, NULL))
			error("Join thread error");
	return ;
}
