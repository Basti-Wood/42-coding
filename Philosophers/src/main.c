#include "../include/philosophers.h"

int main(int ari, char **ars)
{
	t_philo		philos[MAX_PHILO_COUNT];
	t_mutex		forks[MAX_PHILO_COUNT];
	t_engine	engine;

	check_arguments(ari, ars);
	init_all(&engine, forks, philos, ars);
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}