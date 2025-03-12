#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void	signal_action(int pid, char *str)
{
	int	i;
	int	c;

	while (*str)
	{
		c = *str;
		i = 0;
		while (i < 8)
		{
			if ((c >> (7 - i)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		str++;
	}
	// Send NULL terminator
	c = 0;
	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Invalid number of arguments.\n");
		ft_printf("Format: [./client <SERVER ID (PID)> <STRING>]\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		signal_action(ft_atoi(argv[1]), argv[2]);
	}
	return (0);
}
