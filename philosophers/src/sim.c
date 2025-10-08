/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:39:24 by sholz             #+#    #+#             */
/*   Updated: 2025/06/04 18:58:49 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	is_finished(t_philo *philo)
{
	int	i;
	int	finished;

	if (philo[0].must_eat == -1)
		return (false);
	i = 0;
	finished = 0;
	while (i < philo[0].philo_count)
	{
		pthread_mutex_lock(philo->mutexes.meal_lock);
		if (philo[i].meals_eaten >= philo[i].must_eat)
			finished++;
		pthread_mutex_unlock(philo->mutexes.meal_lock);
		i++;
	}
	if (finished == philo[0].philo_count)
		return (true);
	return (false);
}

static int	check_philosopher_death(t_engine *engine, t_philo *philos, int i)
{
	pthread_mutex_lock(philos[i].mutexes.meal_lock);
	if (current_time() - philos[i].times.last_meal > philos[i].times.die)
	{
		pthread_mutex_unlock(philos[i].mutexes.meal_lock);
		put_action(&philos[i], "died");
		set_stop_flag(engine);
		return (1);
	}
	pthread_mutex_unlock(philos[i].mutexes.meal_lock);
	return (0);
}

void	*observer(void *arg)
{
	t_engine	*engine;
	t_philo		*philos;
	int			count;
	int			i;

	engine = (t_engine *)arg;
	philos = engine->philos;
	count = philos[0].philo_count;
	while (1)
	{
		i = -1;
		while (++i < count)
			if (check_philosopher_death(engine, philos, i))
				return (NULL);
		if (is_finished(philos))
		{
			set_stop_flag(engine);
			return (NULL);
		}
	}
	return (NULL);
}

static void	create_philosophers(t_engine *engine, int count)
{
	int				i;
	t_philo_engine	*data;

	i = -1;
	while (++i < count)
	{
		data = malloc(sizeof(t_philo_engine));
		if (!data)
			destroy_all(engine, "malloc error\n", count, 1);
		data->philo = &engine->philos[i];
		data->engine = engine;
		if (pthread_create(&engine->philos[i].thread_id, NULL, start_simulation,
				data) != 0)
		{
			free(data);
			destroy_all(engine, "thread error\n", count, 1);
		}
	}
}

void	launcher(t_engine *engine, int count)
{
	pthread_t	observer_id;
	int			i;

	if (pthread_create(&observer_id, NULL, &observer, engine) != 0)
		destroy_all(engine, "thread error\n", count, 1);
	create_philosophers(engine, count);
	if (pthread_join(observer_id, NULL) != 0)
		destroy_all(engine, "thread error\n", count, 1);
	i = -1;
	while (++i < count)
		pthread_join(engine->philos[i].thread_id, NULL);
}
