/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:30:47 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:28:08 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This function will create a fork. 
	 The fork is used throughout the program.
	 when called the fork will be used to eat -- */

#include "../headers/header.h"

	/* -- This function will create a fork and be used throughout 
	 	the program -- */

int	make_fork(t_main *main)
{
	int	fork;

	main->forks = malloc(sizeof(pthread_mutex_t) * main->input.num_philo + 1);
	if (main->forks == NULL)
		return (FALSE);
	fork = 0;
	while (fork < main->input.num_philo)
	{
		if (pthread_mutex_init(&main->forks[fork], NULL) != 0)
			return (FALSE);
		fork++;
	}
	return (TRUE);
}

	/* -- This program uses threads. 
	  When the program calls the fork is unlocked and can be used -- */

void	unlock_fork(t_main *main)
{
	int	unlock;

	unlock = 0;
	while (unlock < main->input.num_philo)
	{
		pthread_mutex_unlock(&main->forks[unlock]);
		unlock++;
	}
}
