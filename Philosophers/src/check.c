#include "../include/philosophers.h"

void check_arguments(int ari, char **ars)
{
	int i;
	long num;

	if (ari < 5 || ari > 6)
		error_message("Wrong number of arguments \n try ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] (optional)", 1);
	i = 1;
	while (i < ari)
	{
		num = ft_atoi(ars[i]);
		if (i == 1 && (num < 1 || num > MAX_PHILO_COUNT))
			error_message("Wrong number of Philosophers", 1);
		if (i == 5 && (num < 1 || num > INT_MAX)) // Check optional argument
			error_message("Invalid number of required meals", 1);
		if (i != 1 && i !=5 && (num < 0 || num > INT_MAX))
			error_message("Error with time to eat/die/sleep", 1);
		i++;
	}
}