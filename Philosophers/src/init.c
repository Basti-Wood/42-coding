#include "../include/philosophers.h"

void init_philosophers(t_engine *engine, t_philo *philos, t_mutex *forks, char **ars)
{
	int i;
	int philo_count;

	philo_count = ft_atoi(ars[1]);
	i = 0;
	while (i < philo_count)
	{
		philos[i].id = i + 1;
		philos[i].times.die = ft_atoi(ars[2]);
		philos[i].times.eat = ft_atoi(ars[3]);
		philos[i].times.sleep = ft_atoi(ars[4]);
		philos[i].meals_eaten = 0;
		if (ars[5])
			philos[i].must_eat = ft_atoi(ars[5]);
		else
			philos[i].must_eat = -1;
		philos[i].philo_count = philo_count;
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &engine->write_lock;
		philos[i].mutexes.meal_lock = &engine->meal_lock;
		philos[i].mutexes.stop_lock = &engine->stop_lock; // Initialize stop_lock
		philos[i].stop_simulation = &engine->stop_simulation; // Initialize stop_simulation
		i++;
	}
}

void	init_forks(t_engine *engine, t_mutex *forks, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			destroy_all(engine, "Error while Fork init", i, 1);
		i++;
	}
}

// init.c
void init_engine(t_engine *engine, t_philo *philos, t_mutex *forks)
{
    engine->forks = forks;
    engine->philos = philos;
    engine->stop_simulation = false;  // Initialize flag
    
    if(pthread_mutex_init(&engine->stop_lock, NULL) != 0 ||
       pthread_mutex_init(&engine->meal_lock, NULL) != 0 ||
       pthread_mutex_init(&engine->write_lock, NULL) != 0)
    {
        destroy_all(engine, "[Mutex Init ERROR]\n", -1, 1);
    }
}

void	init_all(t_engine *engine, t_mutex *forks, t_philo *philos, char **ars)
{
	init_engine(engine, philos, forks);
	init_forks(engine, forks, ft_atoi(ars[1]));
	init_philosophers(engine, philos, forks, ars);
}