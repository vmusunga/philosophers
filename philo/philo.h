/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:40:48 by vmusunga          #+#    #+#             */
/*   Updated: 2022/05/25 19:39:35 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int				meals;

	unsigned long	last_meal;
	struct s_data	*data;
	pthread_t		philo_thread;
}					t_philo;

typedef struct s_data
{
	int				philo_nb;
	int				meals_nb;
	int				dead;

	unsigned long	tte;
	unsigned long	tts;
	unsigned long	ttd;
	unsigned long	start;

	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	death;
	pthread_mutex_t	writing;
	pthread_mutex_t	meal_time;
	pthread_mutex_t	meal_update;
}				t_data;

/// INIT
int				init_struct(t_data *data, char **av);
int				philo_init(t_data *data);

/// PHILOSOPHERS
int				pepsi(t_data *data);
int				game_over(t_philo *philo, int code);
void			ft_sleep(t_philo *philo, unsigned long time);
void			*life(void *x);

/// UTILS
int				error(char *msg);
int				destroy(t_data *data);
int				input_check(char **av);
unsigned long	current_time(void x);
unsigned long	timediff(unsigned long start);

#endif