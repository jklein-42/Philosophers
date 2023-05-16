/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:17:37 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:21:11 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* --	This file will use the fountion exicution to comple all 
	 * the code together -- */

#include "../headers/header.h"

	//	I will prototype the function with mains 

	/* -- This function is called when the Philosopher needs to eat -- */

int	philosopher_eat(t_main *main, int i)
{
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.left]) != 0)
		return (FALSE);
	if (philo_write(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (pthread_mutex_lock(&main->forks[main->philo[i].fork.right]) != 0)
		return (FALSE);
	if (philo_write(main, main->philo[i].id, B_BLUE, FORK) == FALSE)
		return (FALSE);
	if (philo_write(main, main->philo[i].id, G_CYAN, EAT) == FALSE)
		return (FALSE);
	main->philo[i].time_to_die = call_time();
	time_data(main->input.time_to_eat);
	lock_fork(main, i);
	return (TRUE);
}

	/* -- This function is called when the Philosopher needs to sleep -- */

int	philosopher_sleep(t_main *main, int i)
{
	if (philo_write(main, main->philo[i].id, BLUE, SLEEP) == FALSE)
		return (FALSE);
	time_data(main->input.time_to_sleep);
	return (TRUE);
}

	/* -- This function is called when the Philosopher needs to think -- */

int	philosopher_think(t_main *main, int i)
{
	if (philo_write(main, main->philo[i].id, G_BLUE, THINK) == FALSE)
		return (FALSE);
	return (TRUE);
}

	/* -- This function is called when the Philosopher will die -- */

int	philosopher_dead(t_main *main, int *i)
{
	int	time;

	if (*i == main->input.num_philo)
		*i = 0;
	time = delta_time(main->philo[*i].time_to_die);
	if (time > main->input.time_to_die)
	{
		philo_write(main, main->philo[*i].id, RED, DIED);
		main->philo_dead = TRUE;
		return (TRUE);
	}
	i++;
	return (FALSE);
}

	/* -- This function is called when the Philosopher fork function 
	 * is called -- */

int	lock_fork(t_main *main, int i)
{
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.left]))
		return (FALSE);
	if (pthread_mutex_unlock(&main->forks[main->philo[i].fork.right]))
		return (FALSE);
	main->philo[i].num_of_times_ate++;
	return (TRUE);
}
