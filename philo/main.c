/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/25 18:37:49 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		return (error("Wrong input"));
	input_check(av);

	if (!init_struct(&data, av))
		return (0);
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
