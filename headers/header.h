/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:26:28 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 18:35:46 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

		// This will set the int max limits

# define INT_MAX 2147483647

		// This will set the boolen value TRUE or FALSE

# define TRUE 	1
# define FALSE 	0

		// This will set the colour value of the exicutable program

# define RESET 		"\e[0m"
# define RED 		"\e[0;20;40m"
# define GREEN 		"\e[0;32m"
# define BLUE 		"\e[0;34m"
# define G_BLUE 	"\e[1;32m"
# define B_BLUE 	"\e[1;34m"
# define G_CYAN 	"\e[0;38;5;44m"

		// This is the error log feedback message

# define NUM_ARGS 		"ERROR: The number of argments must be 4 or 5"
# define ARG1 			"ERROR: There is a mistake in number of philosophers"
# define ARG2 			"ERROR: There is a mistake in time to die"
# define ARG3 			"ERROR: There is a mistake in time to eat"
# define ARG4 			"ERROR: There is a mistake in time to sleep"
# define ARG5 			"ERROR: There is a mistake in number of times each \
philosopher must eat"

		// This statment will let you know if the argument is TRUE or FALSE

# define HELP "The number of argments must be 4 or 5:\n\
- arg1 number of philosophers\n\
- arg2 time to die\n\
- arg3 time to eat\n\
- arg4 time to sleep\n\
- arg5 number of times each philosopher must eat (optional)"

		// The Philosopher 
		// "is eating" "is sleeping" "is thinking" "using fork" "has died"

# define EAT 		"is eating"
# define SLEEP 		"is sleeping"
# define THINK 		"is thinking"
# define FORK 		"has taken a fork"
# define DIED 		"died ☠️"

	// Structures prototyping

typedef struct s_input
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_eat;
}					t_input;

typedef struct s_fork
{
	int				left;
	int				right;
}					t_fork;

typedef struct s_philo
{
	int				id;
	int				num_of_times_ate;
	long long		time_to_die;
	t_fork			fork;
	pthread_t		thread;
}					t_philo;

typedef struct s_main
{
	int				n_thread;
	int				philo_dead;
	long long		t0;
	t_input			input;
	t_philo			*philo;
	pthread_t		orchestrator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
}					t_main;

	// File ft_controll.c

int			philosopher_eat(t_main *main, int i);
int			philosopher_sleep(t_main *main, int i);
int			philosopher_think(t_main *main, int i);
int			philosopher_dead(t_main *main, int *i);
int			lock_fork(t_main *main, int i);

	// File ft_handle_err.c

int			err(int arg1, char **arg2, t_main *main);
int			err_input(int arg1, char **arg2, t_main *main);
void		arg_err(t_main *main, int arg);

	// File ft_handle_fork.c

int			make_fork(t_main *main);
void		unlock_fork(t_main *main);

	// File ft_handle_philo.c

int			make_philosopher(t_main *main);
void		philo_struct(t_main *main, int i, int n);

	// File ft_handle_thread.c

int			make_thread(t_main *main);
int			join_thread(t_main *main);
int			breake_thread(t_main *main);

	// File ft_handle_time.c

long long	call_time(void);
long long	delta_time(long long time);
void		time_data(long long time);

	// File ft_main.c

int			main(int arg1, char **arg2);
int			philosopher(t_main *main);

	// File ft_thread_Mutx.c

void		*thread_line(void *arg);
int			thread_compile(t_main *main, int i);
void		*thread_check(void *arg);
int			philo_write(t_main *main, int id, char *colour, char *status);

	// File ft_utils.c

int			ft_atoi(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strlen(const char *s);
void		ft_free(t_main *main);

#endif
