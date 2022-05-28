/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/28 15:39:03 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (error("Wrong input"));
	if (!input_check(av))
		return (0);
	if (!init_struct(&data, av))
		return (0);
	// if (!mutex_init(&data))			segfault 3 310 200 200 + no valgrind
	// 	return (0);
	if (!philo_init(&data))
		return (0);
	if (!destroy(&data))
		return (0);
	if (data.philo)
		free(data.philo);
	if (data.fork)
		free(data.fork);
	return (1);
}
