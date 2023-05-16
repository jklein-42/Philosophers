/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:36:21 by jklein            #+#    #+#             */
/*   Updated: 2023/02/21 17:42:41 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/* -- This is the library function where all the C code is called when needed
	The Philosophers use this code to compile -- */

#include "../headers/header.h"

			/* -- convert ASCII string to integer -- */

int	ft_atoi(const char *str)
{
	int	num;
	int	coefficient;
	int	output;

	num = 0;
	output = 0;
	while (str[num] == 32 || str[num] == '\n' || str[num] == '\t'
		|| str[num] == '\v' || str[num] == '\f' || str[num] == '\r')
		num++;
	if (str[num] == '-')
	{
		coefficient = -1;
		num++;
	}
	else if (str[num] == '+')
		num++;
	while (str[num] >= 48 && str[num] <= 57)
	{
		output = output * 10 + (str[num] - '0');
		num++;
	}
	if (coefficient == -1)
		output = -output;
	return (output);
}

			/* -- compare string -- */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	str;

	if (n == 0)
		return (0);
	str = 0;
	while (s1[str] == s2[str] && s1[str] != '\0' && str < (n - 1))
	{
		str++;
	}
	return ((unsigned char)s1[str] - (unsigned char)s2[str]);
}

			/* -- find length of string -- */

int	ft_strlen(const char *s)
{
	int	str;

	str = 0;
	while (s[str] != '\0')
	{
		str++;
	}
	return (str);
}

	/* -- function will free the program -- */

void	ft_free(t_main *main)
{
	free(main->philo);
	free(main->forks);
}
