/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/06 14:12:05 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data data;
	// struct timeval start;

	if (ac != 5)
		error("Wrong input");
	if (!input_check(av))
		error("Wrong input");

	// gettimeofday(&start, NULL);
	init_struct(&data, av);
	philo_init(&data);
	// destroy(&data);

	// int i = 0;
	// printf("%i, %i, %i, %i, %ld\n", data.philo_nb, data.ttd, data.tte, data.tts, data.philo->start.tv_sec);
	// while (i <= ft_atoi(av[2]))
	// {
	// 	printf("philo %d : %i, %i, %i\n", i, data.philo[i].id, data.philo[i].left_fork, data.philo[i].right_fork);
	// 	i++;
	// }
	return (0);
}