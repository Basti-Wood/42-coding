/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:24 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 18:58:42 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_all(t_engine *engine, t_mutex *forks, t_philo *philos, char **ars)
{
	init_engine(engine, philos, forks);
	init_forks(engine, forks, ft_atoi(ars[1]));
	init_philosophers(engine, philos, forks, ars);
}

static void	*handle_single_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	put_action(philo, "has taken a fork");
	usleep(philo->times.die * 1000);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	return (NULL);
}

void	*start_simulation(void *ptr)
{
	t_philo_engine	*data;
	t_philo			*philo;

	data = (t_philo_engine *)ptr;
	philo = data->philo;
	if (philo->philo_count == 1)
		return (handle_single_philosopher(philo));
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(philo->mutexes.stop_lock);
		if (*philo->stop_simulation)
		{
			pthread_mutex_unlock(philo->mutexes.stop_lock);
			break ;
		}
		pthread_mutex_unlock(philo->mutexes.stop_lock);
		routin(philo);
	}
	free(data);
	return (NULL);
}

int	main(int ari, char **ars)
{
	t_philo		philos[MAX_PHILO_COUNT];
	t_mutex		forks[MAX_PHILO_COUNT];
	t_engine	engine;
	int			i;

	i = 0;
	check_arguments(ari, ars);
	init_all(&engine, forks, philos, ars);
	engine.start_time = current_time();
	while (i < ft_atoi(ars[1]))
	{
		philos[i].times.born_time = engine.start_time;
		philos[i].times.last_meal = engine.start_time;
		i++;
	}
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}
