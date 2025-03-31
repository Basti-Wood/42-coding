#include "../includes/so_long.h"

static void	floodfill(char **map, int x, int y, char wall)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == wall || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	floodfill(map, x + 1, y, wall);
	floodfill(map, x - 1, y, wall);
	floodfill(map, x, y + 1, wall);
	floodfill(map, x, y - 1, wall);
}

static int	check_unreachables(char **map, t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == data->content.collect ||
				map[y][x] == data->content.exit)
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

static int	setup_floodfill(t_data *data, char ***map_copy)
{
	int	px;
	int	py;

	*map_copy = duplicate_map(data->map);
	if (!*map_copy)
		return (0);
	if (!find_player_pos(*map_copy, &px, &py))
	{
		free_map_copy(*map_copy);
		return (0);
	}
	floodfill(*map_copy, px, py, data->content.wall);
	return (1);
}

int	is_doable(t_data *data)
{
	char	**map_copy;
	int		result;

	if (!setup_floodfill(data, &map_copy))
		return (0);
	result = check_unreachables(map_copy, data);
	free_map_copy(map_copy);
	return (result);
}
