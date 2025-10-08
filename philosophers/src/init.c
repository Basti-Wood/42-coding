/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:24 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 17:39:27 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	init_philosopher_data(t_philo *philo, int i, char **args)
{
	philo->id = i + 1;
	philo->times.die = ft_atoi(args[2]);
	philo->times.eat = ft_atoi(args[3]);
	philo->times.sleep = ft_atoi(args[4]);
	philo->meals_eaten = 0;
	if (args[5])
		philo->must_eat = ft_atoi(args[5]);
	else
		philo->must_eat = -1;
	philo->philo_count = ft_atoi(args[1]);
}

static void	assign_forks(t_philo *philo, t_mutex *forks, int i, int count)
{
	philo->mutexes.left_fork = &forks[i];
	if (i == 0)
		philo->mutexes.right_fork = &forks[count - 1];
	else
		philo->mutexes.right_fork = &forks[i - 1];
}

void	init_philosophers(t_engine *engine, t_philo *philos, t_mutex *forks,
		char **args)
{
	int	i;
	int	count;

	count = ft_atoi(args[1]);
	i = -1;
	while (++i < count)
	{
		init_philosopher_data(&philos[i], i, args);
		assign_forks(&philos[i], forks, i, count);
		philos[i].mutexes.write_lock = &engine->write_lock;
		philos[i].mutexes.meal_lock = &engine->meal_lock;
		philos[i].mutexes.stop_lock = &engine->stop_lock;
		philos[i].stop_simulation = &engine->stop_simulation;
	}
}

void	init_forks(t_engine *engine, t_mutex *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(engine, "Error while Fork init", i, 1);
		i++;
	}
}

void	init_engine(t_engine *engine, t_philo *philos, t_mutex *forks)
{
	engine->forks = forks;
	engine->philos = philos;
	engine->stop_simulation = false;
	if (pthread_mutex_init(&engine->stop_lock, NULL) != 0
		|| pthread_mutex_init(&engine->meal_lock, NULL) != 0
		|| pthread_mutex_init(&engine->write_lock, NULL) != 0)
	{
		destroy_all(engine, "[Mutex Init ERROR]\n", -1, 1);
	}
}
