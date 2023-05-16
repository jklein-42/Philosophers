/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_Mutx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:11:09 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:47:15 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

		/* -- The arguments for the thread. 
		 	The code will line up the Philosophers with
			each command. this code will make the philosopher act -- */

#include "../headers/header.h"

	/* -- The thread must be called and exicuted. 
		The code will control the Philosophers -- */

void	*thread_line(void *arg)
{
	t_main	*main;
	int		thread;

	main = (t_main *)arg;
	thread = main->n_thread;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo
			[thread].num_of_times_ate
			&& main->philo_dead == FALSE)
			thread_compile(main, thread);
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (thread_compile(main, thread) == FALSE)
				break ;
		}
	}
	return (NULL);
}

	/* -- The program will execute the Philosophers. 
	 	The thread will be made -- */

int	thread_compile(t_main *main, int i)
{
	if (philosopher_eat(main, i) == FALSE)
		return (FALSE);
	if (main->input.num_of_times_eat != main->philo[i].num_of_times_ate)
	{
		if (philosopher_sleep(main, i) == FALSE)
			return (FALSE);
		if (philosopher_think(main, i) == FALSE)
			return (FALSE);
	}
	return (TRUE);
}

	/* -- The thread will be checked and then made. 
	 	The input will configer the output -- */

void	*thread_check(void *arg)
{
	t_main	*main;
	int		thread;

	main = (t_main *)arg;
	thread = 0;
	if (main->input.num_of_times_eat > 0)
	{
		while (main->input.num_of_times_eat > main->philo
			[thread].num_of_times_ate
			&& main->philo_dead == FALSE)
		{
			if (philosopher_dead(main, &thread) == TRUE)
				break ;
		}
	}
	else
	{
		while (main->philo_dead == FALSE)
		{
			if (philosopher_dead(main, &thread) == TRUE)
				break ;
		}
	}
	return (NULL);
}

	/* -- This function will write the the Philosopher action -- */

int	philo_write(t_main *main, int id, char *colour, char *status)
{
	long long	now;

	now = delta_time(main->t0);
	if (main->philo_dead == TRUE)
		return (FALSE);
	pthread_mutex_lock(&main->write);
	if (main->philo_dead == TRUE)
	{
		pthread_mutex_unlock(&main->write);
		return (FALSE);
	}
	else
		printf("%s%-10lld %-3d %-30s%s\n", colour, now, id, status, RESET);
	pthread_mutex_unlock(&main->write);
	return (TRUE);
}
