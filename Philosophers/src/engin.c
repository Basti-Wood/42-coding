#include "../include/philosophers.h"

bool is_finished(t_philo *philo)
{
	int i;
	int finished;

	if (philo[0].must_eat == -1) // No meal limit
		return (false);
	i = 0;
	finished = 0;
	while (i < philo[0].philo_count) // Correct loop condition
	{
		pthread_mutex_lock(philo->mutexes.meal_lock);
		if (philo[i].meals_eaten >= philo[i].must_eat)
			finished++;
		pthread_mutex_unlock(philo->mutexes.meal_lock);
		i++;
	}
	if (finished == philo[0].philo_count)
	{
		pthread_mutex_lock(philo->mutexes.write_lock);
		return (true);
	}
	return (false);
}

void *observer(void *philo)
{
    t_philo *tmp;
    int i;
    int philo_count;

    tmp = (t_philo *)philo;
    philo_count = tmp[0].philo_count;
    while (1)
    {
        i = 0;
        while (i < philo_count)
        {
            pthread_mutex_lock(tmp[i].mutexes.meal_lock);
            if (current_time() - tmp[i].times.last_meal > tmp[i].times.die)
            {
                pthread_mutex_unlock(tmp[i].mutexes.meal_lock);
                put_action(&tmp[i], "died ☠️");
                pthread_mutex_lock(tmp->mutexes.write_lock);
                return (NULL);
            }
            pthread_mutex_unlock(tmp[i].mutexes.meal_lock);
            i++;
        }
        if (is_finished(tmp))
            return (NULL);
    }
    return (NULL);
}

void routin(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.right_fork);
	put_action(philo, "Has Taken right Fork 🍴");
	pthread_mutex_lock(philo->mutexes.left_fork);
	put_action(philo, "Has Taken left Fork 🍴");
	pthread_mutex_lock(philo->mutexes.meal_lock);
	put_action(philo, " is eating 🍗");
	philo->times.last_meal = current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	ft_usleep(philo->times.eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	put_action(philo, " is sleeping 😴");
	ft_usleep(philo->times.sleep);
	put_action(philo, " is thinking 🤔");	
}

void	*start_simulation(void *ptr)
{
	t_philo *philo;

	philo = (t_philo*) ptr;
	if (philo->id % 2 == 0)
		usleep(1);
	pthread_mutex_lock(philo->mutexes.meal_lock);
	philo->times.born_time = current_time();
	philo->times.last_meal = current_time();
	pthread_mutex_unlock(philo->mutexes.meal_lock);
	while(1)
		routin(philo);
	return(NULL);
}

void	launcher(t_engine *engine, int count)
{
	pthread_t observer_id;
	int i;

	i = 0;
	if (pthread_create(&observer_id, NULL, &observer, engine->philos) != 0)
		destroy_all(engine, "thread error", count, 1);
	while (i < count)
	{
		if (pthread_create(&engine->philos[i].thread_id, NULL,
				start_simulation, &engine->philos[i]) != 0)
			destroy_all(engine, "thread error", count, 1);
		i++;
	}
	if (pthread_join(observer_id, NULL) != 0)
		destroy_all(engine, "thread error\n", count, 1);
	// Let threads finish their current actions before detaching
	i = 0;
	while (i < count)
	{
		pthread_detach(engine->philos[i].thread_id);
		i++;
	}
}