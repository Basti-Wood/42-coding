/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:16 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 18:58:25 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	check_arguments(int ari, char **ars)
{
	int		i;
	long	num;

	if (ari < 5 || ari > 6)
		ft_error("Wrong number of arguments \n 5-6 numbers required", 1);
	i = 1;
	while (i < ari)
	{
		num = ft_atoi(ars[i]);
		if (i == 1 && (num < 1 || num > MAX_PHILO_COUNT))
			ft_error("Wrong number of Philosophers", 1);
		if (i == 5 && (num < 1 || num > INT_MAX))
			ft_error("Invalid number of required meals", 1);
		if (i != 1 && i != 5 && (num < 0 || num > INT_MAX))
			ft_error("Error with time to eat/die/sleep", 1);
		i++;
	}
}
