/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:24 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 18:58:58 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_error(char *str, int i)
{
	printf("Error\n%s", str);
	exit(i);
}

size_t	current_time(void)
{
	t_timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Get Time\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls, t_philo *philo)
{
	size_t	start;
	size_t	remaining;

	start = current_time();
	while (current_time() - start < mls)
	{
		pthread_mutex_lock(philo->mutexes.stop_lock);
		if (*philo->stop_simulation)
		{
			pthread_mutex_unlock(philo->mutexes.stop_lock);
			break ;
		}
		pthread_mutex_unlock(philo->mutexes.stop_lock);
		remaining = mls - (current_time() - start);
		if (remaining > 10)
			usleep(1000);
		else
			usleep(100);
	}
}

void	put_action(t_philo *philo, char *action)
{
	size_t	event_time;

	event_time = current_time() - philo->times.born_time;
	pthread_mutex_lock(philo->mutexes.stop_lock);
	if (*philo->stop_simulation)
	{
		pthread_mutex_unlock(philo->mutexes.stop_lock);
		return ;
	}
	pthread_mutex_unlock(philo->mutexes.stop_lock);
	pthread_mutex_lock(philo->mutexes.write_lock);
	pthread_mutex_lock(philo->mutexes.stop_lock);
	if (*philo->stop_simulation)
	{
		pthread_mutex_unlock(philo->mutexes.stop_lock);
		pthread_mutex_unlock(philo->mutexes.write_lock);
		return ;
	}
	pthread_mutex_unlock(philo->mutexes.stop_lock);
	printf("%ld %d %s\n", event_time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

void	destroy_all(t_engine *engine, char *str, int count, int signal)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&engine->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&engine->write_lock);
	pthread_mutex_destroy(&engine->meal_lock);
	if (str)
		ft_error(str, signal);
}
