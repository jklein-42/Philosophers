/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_err.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 19:18:21 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:24:53 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This function will control the error outputs. the code will identifie
	sections of this code and exicutue it alltogether -- */

#include "../headers/header.h"

	/* -- This will control the handling of the errors 
	  the function output -- */

int	err(int arg1, char **arg2, t_main *main)
{
	if (arg1 == 2 && !ft_strncmp(arg2[1], "help", 4)
		&& ft_strlen(arg2[1]) == 4)
	{
		printf("%s%s%s\n", GREEN, HELP, RESET);
		return (FALSE);
	}
	else if (err_input(arg1, arg2, main) == FALSE)
	{
		printf("%s%s%s\n", RED, NUM_ARGS, RESET);
		return (FALSE);
	}
	else
	{
		arg_err(main, arg1);
		if (!main->input.num_philo || !main->input.time_to_die
			|| !main->input.time_to_eat || !main->input.time_to_sleep
			|| (arg1 == 6 && !main->input.num_of_times_eat))
			return (FALSE);
	}
	return (TRUE);
}

	/* -- Using this fountion to control the structer -- */

int	err_input(int arg1, char **arg2, t_main *main)
{
	if (arg1 == 5 || arg1 == 6)
	{
		main->input.num_philo = ft_atoi(arg2[1]);
		main->input.time_to_die = ft_atoi(arg2[2]);
		main->input.time_to_eat = ft_atoi(arg2[3]);
		main->input.time_to_sleep = ft_atoi(arg2[4]);
		if (arg1 == 6)
			main->input.num_of_times_eat = ft_atoi(arg2[5]);
		else
			main->input.num_of_times_eat = -1;
		return (TRUE);
	}
	return (FALSE);
}

	/* -- This void function will have no return value. 
	 * error message inside -- */

void	arg_err(t_main *main, int arg1)
{
	if (!main->input.num_philo)
		printf("%s%s%s\n", RED, ARG1, RESET);
	if (!main->input.time_to_die)
		printf("%s%s%s\n", RED, ARG2, RESET);
	if (!main->input.time_to_eat)
		printf("%s%s%s\n", RED, ARG3, RESET);
	if (!main->input.time_to_sleep)
		printf("%s%s%s\n", RED, ARG4, RESET);
	if (arg1 == 6 && !main->input.num_of_times_eat)
		printf("%s%s%s\n", RED, ARG5, RESET);
}
