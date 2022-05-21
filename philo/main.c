/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:14:55 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/21 17:09:08 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 5 && ac != 6)
		error("Wrong input");
	input_check(av);

	init_struct(&data, av);
	philo_init(&data);
	destroy(&data);
	return (0);
}