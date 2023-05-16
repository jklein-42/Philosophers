/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 21:45:15 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:52:15 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This code will make the Philosophers. 
	 	the Philosophers will be uesed in this program
		to commit to picific tasks. the Philosopher will 
		"Eating" "Fork" "Sleeping" "Died" -- */

#include "../headers/header.h"

	/* -- The Philosopher needs to be made. here the Philosopher is made 
	 	for the program -- */

int	make_philosopher(t_main *main)
{
	int	make;
	int	philo;

	main->philo = malloc(sizeof(t_philo) * (main->input.num_philo + 1));
	if (main->philo == NULL)
		return (FALSE);
	make = 0;
	philo = 1;
	while (philo < main->input.num_philo)
	{
		philo_struct(main, make, philo);
		make++;
		philo++;
	}
	philo = 0;
	philo_struct(main, make, philo);
	return (TRUE);
}

	/* -- Here the structure of the code is formed. the structure of 
	 	"Eating" "Fork" "Sleeping" "Died" -- */

void	philo_struct(t_main *main, int i, int n)
{
	main->philo[i].id = i + 1;
	main->philo[i].num_of_times_ate = 0;
	main->philo[i].time_to_die = 0;
	main->philo[i].fork.left = i;
	main->philo[i].fork.right = n;
}
