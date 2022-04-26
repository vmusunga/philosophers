/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/26 14:19:30 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct(t_data *data, t_philo *philo, char **av)
{
	data->philo_nb = ft_atoi(av[1]);
	//data->forks = data->philo_nb;

	philo->is_alive = 1;

	data->ttd = ft_atoi(av[2]);
	data->tte = ft_atoi(av[3]);
	data->tts = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	t_data data;
	t_philo philo;

	if (ac != 5)
		error("Wrong input");
	if (!input_check(av))
		error("Wrong input");
	init_struct(&data, &philo, av);
	printf("%i, %i, %i, %i", data.philo_nb, data.ttd, data.tte, data.tts);
	return (0);
}