#include "../includes/so_long.h"

int	ft_check_col(char *map_line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (map_line[i])
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Map column not close", 1);
		return (0);
	}
	data->width = i;
	return (1);
}

int	ft_check_line(char *map_line, char wall)
{
	int	i;

	if (!map_line || map_line[0] == '\0')
	{
		ft_error("Empty line in map", 1);
		return (0);
	}
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] != wall)
		{
			ft_error("Map line not close", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_other(char *map_line, t_cunt *content)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		if (content->count_e > 1 || content->count_p > 1)
		{
			ft_error("Wrong number of player or exit", 1);
			return (0);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player
			&& map_line[i] != content->exit && map_line[i] != content->collect
			&& map_line[i] != content->space)
		{
			ft_error("Unknown symbol(s) in map", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_check_content(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		while (data->map[i][y])
		{
			if (data->map[i][y] == data->content.collect)
				data->content.count_c += 1;
			if (data->map[i][y] == data->content.player)
				data->content.count_p += 1;
			if (data->map[i][y] == data->content.exit)
				data->content.count_e += 1;
			y++;
		}
		y = 0;
		i++;
	}
}

int	ft_check_format(char **map)
{
	int	y;
	int	x;
	int	count_x;

	x = 0;
	y = 0;
	count_x = 0;
	while (map[0][count_x])
		count_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != count_x)
		{
			ft_error("Map must be a rectangloid!", 1);
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
