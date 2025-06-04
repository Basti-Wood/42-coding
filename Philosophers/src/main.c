#include "../include/philosophers.h"

int main(int ari, char **ars)
{
    t_philo     philos[MAX_PHILO_COUNT] = {{0}};
    t_mutex     forks[MAX_PHILO_COUNT] = {{{0}}};
    t_engine    engine = {0};

	check_arguments(ari, ars);
	init_all(&engine, forks, philos, ars);
    engine.start_time = current_time();
    for (int i = 0; i < ft_atoi(ars[1]); i++) {
        philos[i].times.born_time = engine.start_time;
        philos[i].times.last_meal = engine.start_time;
    }
	launcher(&engine, philos[0].philo_count);
	destroy_all(&engine, NULL, philos[0].philo_count, 0);
	return (0);
}