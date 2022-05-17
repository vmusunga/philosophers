/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/17 16:08:27 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	current_time()
{
	unsigned long	time;
	struct timeval tmp;

	gettimeofday(&tmp, NULL);
	time = (tmp.tv_sec * 1000) + (tmp.tv_usec / 1000);
	return (time);
}

unsigned long	timediff(unsigned long start)
{
	struct timeval cur;
	unsigned long diff;
	// unsigned long start;

	gettimeofday(&cur, NULL);
	//start = philo->data->start;
	diff = ((cur.tv_sec * 1000) + (cur.tv_usec / 1000)) - start;
	return (diff);
}

void	destroy(t_data *data)
{
	int i;

	i = 0;
	while (i < data->philo_nb)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
}

int	input_check(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (!ft_isdigit(ft_atoi(av[i])))
			return (1);
		i++;
	}
	if (ft_atoi(av[1]) > 200)
		error("Bruh.");
	return (0);
}

void	free_tab(char *str, char *str2)
{
	free(str2);
	free(str);
	return ;
}

void	free_tab2(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
	return ;
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_SUCCESS);
}
