#include "../include/philosophers.h"

void error_message(char *str, int i)
{
	printf("Error\n%s", str);
	exit(i);
}

size_t current_time()
{
	t_timeval time;

	if (gettimeofday(&time, NULL) == -1)
		error_message("Get Time\n", 1);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t mls)
{
	size_t	start;

	start = current_time();
	while (current_time() - start < mls)
		usleep(500);
}

void	put_action(t_philo *philo, char *action)
{
	size_t time;

	pthread_mutex_lock(philo->mutexes.write_lock);
	time = current_time() - philo->times.born_time;
	printf("%ld %d %s\n", time, philo->id, action);
	pthread_mutex_unlock(philo->mutexes.write_lock);
}

void	destroy_all(t_engine *engine, char *str, int count, int signal)
{
	while (count >= 0)
	{
		pthread_mutex_destroy(&engine->forks[count]);
		count--;
	}
	pthread_mutex_destroy(&engine->write_lock);
	pthread_mutex_destroy(&engine->meal_lock);
	if(str)
		error_message(str, signal);
}