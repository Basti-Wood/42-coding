#include "../include/philosophers.h"

bool is_finished(t_philo *philo)
{
    int i;
    int finished;

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
        return (true); // Removed mutex lock here
    return (false);
}

// sim.c
void *observer(void *arg)
{
    t_engine *engine = (t_engine *)arg;
    t_philo *philos = engine->philos;
    int count = philos[0].philo_count;

    while (1)
    {
        int i = -1;
        while (++i < count)
        {
            pthread_mutex_lock(philos[i].mutexes.meal_lock);
            if (current_time() - philos[i].times.last_meal > philos[i].times.die)
            {
                pthread_mutex_unlock(philos[i].mutexes.meal_lock);
                put_action(&philos[i], "died");
                set_stop_flag(engine);  // Set stop flag
                return NULL;
            }
            pthread_mutex_unlock(philos[i].mutexes.meal_lock);
        }
        if (is_finished(philos))
        {
            set_stop_flag(engine);  // Set stop flag
            return NULL;
        }
    }
    return NULL;
}
void set_stop_flag(t_engine *engine)
{
    pthread_mutex_lock(&engine->stop_lock);
    engine->stop_simulation = true;
    pthread_mutex_unlock(&engine->stop_lock);
}

// sim.c
void routin(t_philo *philo) {
    pthread_mutex_t *first_fork;
    pthread_mutex_t *second_fork;

    // Determine fork order to avoid deadlock
    first_fork = philo->mutexes.left_fork;
    second_fork = philo->mutexes.right_fork;
    if (philo->mutexes.left_fork > philo->mutexes.right_fork) {
        first_fork = philo->mutexes.right_fork;
        second_fork = philo->mutexes.left_fork;
    }

    // Lock forks
    pthread_mutex_lock(first_fork);
    put_action(philo, "has taken a fork");
    pthread_mutex_lock(second_fork);
    put_action(philo, "has taken a fork");

    // Update meal status
    pthread_mutex_lock(philo->mutexes.meal_lock);
    put_action(philo, "is eating");
    philo->times.last_meal = current_time();
    philo->meals_eaten++;
    pthread_mutex_unlock(philo->mutexes.meal_lock);

    ft_usleep(philo->times.eat, philo);
    
    // Release forks
    pthread_mutex_unlock(second_fork);
    pthread_mutex_unlock(first_fork);
    
    put_action(philo, "is sleeping");
    ft_usleep(philo->times.sleep, philo);
    put_action(philo, "is thinking");
}

void *start_simulation(void *ptr)
{
    t_philo_engine *data = (t_philo_engine*)ptr;
    t_philo *philo = data->philo;

    if (philo->id % 2 == 0)
        usleep(1000);
    
    
    while (1)
    {
        pthread_mutex_lock(philo->mutexes.stop_lock);
        if (*philo->stop_simulation) {
            pthread_mutex_unlock(philo->mutexes.stop_lock);
            break;
        }
        pthread_mutex_unlock(philo->mutexes.stop_lock);
        
        routin(philo);
    }
    free(data);
    return NULL;
}
void launcher(t_engine *engine, int count)
{
    pthread_t observer_id;
    int i = -1;

    if (pthread_create(&observer_id, NULL, &observer, engine) != 0)
        destroy_all(engine, "thread error\n", count, 1);
    
    while (++i < count)
    {
        t_philo_engine *data = malloc(sizeof(t_philo_engine));
        if (!data)
            destroy_all(engine, "malloc error\n", count, 1);
        data->philo = &engine->philos[i];
        data->engine = engine;
        
        if (pthread_create(&engine->philos[i].thread_id, NULL,
                start_simulation, data) != 0)
        {
            free(data);
            destroy_all(engine, "thread error\n", count, 1);
        }
    }
    
    if (pthread_join(observer_id, NULL) != 0)
        destroy_all(engine, "thread error\n", count, 1);
    
    i = -1;
    while (++i < count)
        pthread_join(engine->philos[i].thread_id, NULL);
}