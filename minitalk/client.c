/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:18:21 by sholz             #+#    #+#             */
/*   Updated: 2025/02/22 15:18:29 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

void	send_str(int pid, char *str)
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
			usleep(175);
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_str(ft_atoi(argv[1]), argv[2]);
	}
	else
	{
		ft_printf("Wrong Format You Doughnut!\n");
		ft_printf("Right Format is 'SERVER ID' 'Message'\n");
	}
	return (0);
}
