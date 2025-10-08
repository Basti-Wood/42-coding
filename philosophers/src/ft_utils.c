/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:24 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 18:58:33 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	set_stop_flag(t_engine *engine)
{
	pthread_mutex_lock(&engine->stop_lock);
	engine->stop_simulation = true;
	pthread_mutex_unlock(&engine->stop_lock);
}

void	routin(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	first_fork = philo->mutexes.left_fork;
	second_fork = philo->mutexes.right_fork;
	if (philo->mutexes.left_fork > philo->mutexes.right_fork)
	{
		first_fork = philo->mutexes.right_fork;
		second_fork = philo->mutexes.left_fork;
	}
	put_action(philo, "is thinking");
	pthread_mutex_lock(first_fork);
	put_action(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);
	put_action(philo, "has taken a fork");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	put_action(philo, "is eating");
	philo->times.last_meal = current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat, philo);
	pthread_mutex_unlock(second_fork);
	pthread_mutex_unlock(first_fork);
	put_action(philo, "is sleeping");
	ft_usleep(philo->times.sleep, philo);
}
