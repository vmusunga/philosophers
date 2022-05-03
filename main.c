/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/03 16:47:08 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, char **av)
{
	int i;

	i = 0;
	data->philo_nb = ft_atoi(av[1]);

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
	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
}

void	philo_init(t_data *data)
{
	int i;

	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_create(&data->philo[i].philo_thread, NULL, &life, &data)) // ATTENTION
			error("Thread error");
	}
	i = -1;
	while (++i < data->philo_nb)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL))
			error("Join thread error");
	}
	i = 0;
	while (i < data->philo_nb)
	{
		data->philo[i].id = i;
		data->philo[i].is_alive = 1;
		data->philo[i].left_fork = i;
		data->philo[i].right_fork = (i + 1) % data->philo_nb;
		data->philo[i].last_meal = 0;
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	t_data data;
	// t_philo philo;

	if (ac != 5)
		error("Wrong input");
	if (!input_check(av))
		error("Wrong input");

	init_struct(&data, av);
	philo_init(&data);
	destroy(&data);

	// int i = 0;
	printf("%i, %i, %i, %i\n", data.philo_nb, data.ttd, data.tte, data.tts);
	// while (i <= ft_atoi(av[2]))
	// {
	// 	printf("philo %d : %i, %i, %i\n", i, data.philo[i].id, data.philo[i].left_fork, data.philo[i].right_fork);
	// 	i++;
	// }
	return (0);
}