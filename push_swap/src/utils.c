/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 13:20:57 by sholz             #+#    #+#             */
/*   Updated: 2025/03/15 13:21:00 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' \
			&& argv[i][j] != '-')
				return (-1);
			else if (ft_isdigit(argv[i][j]) && (argv[i][j + 1] == ' ' \
			|| argv[i][j + 1] == '\0'))
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

long	ft_atoi(const char *str)
{
	long int		i;
	long int		sign;
	long int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i += 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}

void	check_range(char **number, int *nbr)
{
	int			i;
	long int	num;

	i = 0;
	num = 0;
	while (number[i])
	{
		if (ft_strlen(number[i]) > 11)
		{
			free_array(number);
			free(nbr);
			ft_error("Number too big", 1);
		}
		num = ft_atoi(number[i]);
		if (num > 2147483647 || num < -2147483648)
		{
			free_array(number);
			free(nbr);
			ft_error("Number is too big", 1);
		}
		i++;
	}
}

int	*arg_parse(int argc, char **argv, int count)
{
	char	**s_numbers;
	int		*numbers;
	int		i;
	int		j;
	int		k;

	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (++i < argc)
	{
		s_numbers = ft_split(argv[i], ' ');
		if (!s_numbers)
			ft_error("", 1);
		check_range(s_numbers, numbers);
		k = 0;
		while (s_numbers[k])
			numbers[j++] = ft_atoi(s_numbers[k++]);
		free_array(s_numbers);
	}
	return (numbers);
}

void	ft_error(char *str, int i)
{
	ft_printf("Error\n%s", str);
	exit(i);
}
