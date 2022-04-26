/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:40:48 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/26 14:12:24 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>

# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# include "libft/libft.h"


typedef struct s_philo
{
	int id;
	int philo;
	int is_alive;
}				t_philo;

typedef struct s_data
{
	int philo_nb;

	int tte;
	int tts;
	int ttd;

	pthread_t forks;
}				t_data;

/// UTILS
int		input_check(char **av);
void	error(char *msg);
void	free_tab2(char **str);
void	free_tab(char *str, char *str2);

#endif