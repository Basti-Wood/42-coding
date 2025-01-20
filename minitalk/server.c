#include "libft/libft.h"
#include <signal.h>

static void message_manager(int bit)
{
		int	i;

	i = 0;
	g_msg.c += ((bit & 1) << g_msg.i);
	g_msg.i++;
	if (g_msg.i == 7)
	{
		ft_printf("%c", g_msg.c);
		if (!g_msg.c)
			ft_printf("\n");
		g_msg.c = 0;
		g_msg.i = 0;
	}
}

int main(void)
{
	ft_printf("Welcome to THE Server! \n Here is my PHD. or PID? WHO KNOWS‽ \n %i", getpid())
		while (1)
	{
		signal(SIGUSR2, message_manager);
		signal(SIGUSR1, message_manager);
		pause();
	}
	return (0);
}