/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:40:48 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/06 15:24:07 by vic              ###   ########.fr       */
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
	int				id;
	int				left_fork;
	int				right_fork;
	int				is_alive;

	unsigned long	last_meal;
	struct s_data	*data;
	pthread_t		philo_thread;
}					t_philo;

typedef struct s_data
{
	int philo_nb;

	unsigned long	tte;
	unsigned long	tts;
	unsigned long	ttd;
	unsigned long	start;

	t_philo			*philo;
	pthread_mutex_t	*fork;
}				t_data;

/// INIT
void	init_struct(t_data *data, char **av);
void	philo_init(t_data *data);

/// PHILOSOPHERS
void	*life();

/// UTILS
unsigned long	current_time();
unsigned long	timediff(t_philo *philo);
void	destroy(t_data *data);
int		input_check(char **av);
void	error(char *msg);
void	free_tab2(char **str);
void	free_tab(char *str, char *str2);

#endif