/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:24:07 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 19:47:13 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This is the main function. all the code will exicute here. 
	 	The Philosophers
	code will compile here with the threads run there process -- */

#include "../headers/header.h"

	/* -- The threads and functions will be called here. 
	 It will take in the aguments -- */

int	philosopher(t_main *main);

int	main(int arg1, char **arg2)
{
	t_main	main;

	if (err(arg1, arg2, &main) == FALSE)
		return (1);
	if (make_philosopher(&main) == FALSE)
		return (1);
	if (make_fork(&main) == FALSE)
		return (1);
	if (main.input.num_philo == 1)
	{
		if (philosopher(&main) == FALSE)
			return (1);
		return (0);
	}
	if (make_thread(&main) == FALSE)
		return (1);
	if (breake_thread(&main) == FALSE)
		return (1);
	ft_free(&main);
	return (0);
}

	/* -- The Philosopher function will set the compile here. 
	 	The input and output -- */

int	philosopher(t_main *main)
{
	if (pthread_mutex_init(&main->write, NULL) != 0)
		return (FALSE);
	main->t0 = call_time();
	philo_write(main, 1, B_BLUE, FORK);
	time_data(main->input.time_to_die);
	philo_write(main, 1, RED, DIED);
	ft_free(main);
	return (TRUE);
}
