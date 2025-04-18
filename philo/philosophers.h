/* ************************************************************************************** */
/*                                                                                        */
/*                                                                   :::      ::::::::    */
/*   philosophers.h                                                :+:      :+:    :+:    */
/*                                                               +:+ +:+         +:+      */
/*   By: aaycan <aaycan@student.42kocaeli.com.tr>              +#+  +:+       +#+         */
/*                                                           +#+#+#+#+#+   +#+            */
/*   Created: 2025/04/18 16:27:45 by aaycan                       #+#    #+#              */
/*   Updated: 2025/04/18 16:27:45 by aaycan                      ###   ########.tr        */
/*                                                                                        */
/* ************************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <pthread.h>
#include <stddef.h>

typedef struct s_philosopher
{
	int				philo_id;
	int				eating_flag;
	int				sleeping_flag;
	int				thinking_flag;
	int				left_fork;
	int				right_fork;
	size_t			wait_time;
	int				dead_flag;
	pthread_mutex_t	mutex_fork;
	pthread_t		philo_thread;
	int				num_of_philo;
	int				to_die;
	int				to_eat;
	int				to_sleep;
	int				eat_count;
}t_philo;

int			ft_atoi_mod(const char *str);
int			check_arguments(int argc, char **argv);
void		init_philosophers(t_philo *philosophers, char **argv, int philo_count, int argc);
long long	init_process(t_philo *philosophers, int philo_count);
int			fail_free(t_philo *philosophers, int philo_count, long long error_code);
void		mutex_destroy_func(t_philo *philosophers, int mutex_count);
void		free_philosophers(t_philo *philosophers, int philo_count);

#endif