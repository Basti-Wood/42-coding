#include "../includes/so_long.h"

int	map_height(char **map)
{
	int	h;

	h = 0;
	while (map[h])
		h++;
	return (h);
}

char	**duplicate_map(char **map)
{
	int		rows;
	int		i;
	char	**copy;

	rows = map_height(map);
	i = 0;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	while (i < rows)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[rows] = NULL;
	return (copy);
}

void	free_map_copy(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	find_player_pos(char **map, int *x, int *y)
{
	*y = 0;
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
			{
				return (1);
			}
			(*x)++;
		}
		(*y)++;
	}
	return (0);
}
