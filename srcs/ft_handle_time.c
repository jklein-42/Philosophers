/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_time.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:08:21 by jklein            #+#    #+#             */
/*   Updated: 2023/02/27 15:40:12 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This function will compile in real time. the code has to decleare time
	the threads will use time to complete a process -- */

#include "../headers/header.h"

	/* -- The function will call time here. 
	 	when needed the time will start here -- */

long long	call_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}

	/* -- The time will run when this command is called -- */

long long	delta_time(long long time)
{
	if (time > 0)
		return (call_time() - time);
	return (0);
}

	/* -- Time data is stored with this varible. 
	 	There is no return value with this function -- */

void	time_data(long long time)
{
	usleep(time * 1000);
}
