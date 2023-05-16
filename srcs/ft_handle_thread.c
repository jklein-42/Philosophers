/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_thread.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:56:19 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 22:56:06 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- The program will use threads. the thread must be called. 
	 	Exicuted and destroyed.
		This function will control the threads here -- */

#include "../headers/header.h"

	/* -- The thread is created here. 
	 	this will start the thread for the program -- */

int	make_thread(t_main *main)
{
	int	thread;

	thread = 0;
	main->philo_dead = FALSE;
	main->t0 = call_time();
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	while (thread < main->input.num_philo)
	{
		main->n_thread = thread;
		if (pthread_create(&main->philo[thread].thread,
				NULL, &thread_line, (void *) main) != 0)
			return (FALSE);
		thread++;
		usleep(1000);
	}
	if (pthread_create(&main->orchestrator, NULL, &thread_check,
			(void *) main) != 0)
		return (FALSE);
	usleep(1000);
	if (join_thread(main) == FALSE)
		return (FALSE);
	return (TRUE);
}

	/* -- The thread must rejoin with the program.
	 	 here the code conects the threads after being exicuted -- */

int	join_thread(t_main *main)
{
	int	join;

	join = 0;
	while (join < main->input.num_philo)
	{
		if (pthread_join(main->philo[join].thread, NULL) != 0)
			return (FALSE);
		join++;
	}
	if (pthread_join(main->orchestrator, NULL) != 0)
		return (FALSE);
	return (TRUE);
}

	/* -- The thread must be destroyed to breake the compiling in a loop -- */

int	breake_thread(t_main *main)
{
	int	destroy;

	destroy = 0;
	while (destroy < main->input.num_philo)
	{
		pthread_mutex_destroy(&main->forks[destroy]);
		destroy++;
	}
	pthread_mutex_destroy(&main->write);
	return (TRUE);
}
