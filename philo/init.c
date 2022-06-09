/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:01 by vic               #+#    #+#             */
/*   Updated: 2022/06/09 18:08:17 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	input_check(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!isdigit_check(av[i]))
			return (error("Only digits allowed"));
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		return (error("Bruh."));
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60 || (av[5] && ft_atoi(av[5]) <= 0))
		return (error("Under minimal values"));
	if (ft_atoi(av[1]) == 1)
	{
		usleep(ft_atoi(av[2]));
		printf("%d %d %s\n", ft_atoi(av[2]), 1, "died");
		return (0);
	}
	return (1);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->death, NULL))
		return (error("ICIMalloc error"));
	if (pthread_mutex_init(&data->writing, NULL))
		return (error("Malloc error"));
	if (pthread_mutex_init(&data->meal_time, NULL))
		return (error("Malloc error"));
	if (pthread_mutex_init(&data->meal_update, NULL))
		return (error("Malloc error"));
	data->fork = malloc(sizeof(pthread_mutex_t) * data->philo_nb);
	if (!data->fork)
		return (error("Malloc error"));
	while (i < data->philo_nb)
	{
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (error("Fork error"));
		i++;
	}
	return (1);
}

int	init_struct(t_data *data, char **av)
{
	int	i;

	i = 0;
	data->philo_nb = (ft_atoi(av[1]));
	data->ttd = (ft_atoi(av[2]));
	data->tte = (ft_atoi(av[3]));
	data->tts = (ft_atoi(av[4]));
	data->dead = 0;
	data->meals_nb = -1;
	if (av[5] && (ft_atoi(av[5]) > 0))
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
		if (pthread_mutex_init(&data->fork[i], NULL))
			return (error("Fork error"));
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
	while (++i < data->philo_nb )
		if (pthread_create(&data->philo[i].philo_thread, NULL,
				life, &data->philo[i]))
			return (error("Thread error"));
	if (!pepsi(data))
		return (0);
	i = -1;
	while (++i < data->philo_nb)
		if (pthread_join(data->philo[i].philo_thread, NULL))
			return (error("Join thread error"));
	return (1);
}
