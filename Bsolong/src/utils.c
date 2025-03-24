
#include "../includes/so_long.h"

int	ft_same_char(char *str)
{
	int		i;
	char	buff;

	i = 0;
	buff = '1';
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] != buff && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(char *str, int i)
{
	printf("Error\n%s\n", str);//ft_PRINTF DO NOT FORGET AAAAAAAHHHHHHHHHHH
	exit(i);
}


