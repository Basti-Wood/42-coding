#ifndef PHILO_H
#define PHILO_H

#define MAX_PHILO_COUNT 255

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h>

typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

// Forward declare t_engine
typedef struct s_engine t_engine;

typedef struct s_mutexes
{
	t_mutex	*left_fork;
	t_mutex	*right_fork;
	t_mutex	*write_lock;
	t_mutex	*meal_lock;
	// Change stop_lock to be a pointer here as it refers to engine's stop_lock
	t_mutex	*stop_lock;
}	t_mutexes;

typedef struct s_times
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
	size_t	last_meal;
	size_t	born_time;
}	t_times;

typedef struct s_philo
{
	int			id;
	t_times		times;
	t_mutexes	mutexes;
	int			must_eat;
	pthread_t	thread_id;
	int			meals_eaten;
	int			philo_count;
	bool		*stop_simulation;
}	t_philo;

struct s_engine
{
    t_mutex *forks;
    t_philo *philos;
    t_mutex meal_lock;
    t_mutex write_lock;
    t_mutex stop_lock;
	size_t      start_time;
    bool stop_simulation;
};

typedef struct s_philo_engine
{
    t_philo *philo;
    t_engine *engine;
} t_philo_engine;

void check_arguments(int ari, char **ars);
bool is_finished(t_philo *philo);
void	*observer(void *philo);
void routin(t_philo *philo);
void	*start_simulation(void *ptr);
void	launcher(t_engine *engine, int count);
void	init_all(t_engine *engine, t_mutex *forks, t_philo *philos, char **ars);
size_t ft_strlen(char *str);
long ft_atoi(char *str);
void ft_error(char *str, int i);
size_t current_time();
void	ft_usleep(size_t mls, t_philo *philo);
void put_action(t_philo *philo, char *action);
void	destroy_all(t_engine *engine, char *str, int count, int signal);
void set_stop_flag(t_engine *engine);


#endif