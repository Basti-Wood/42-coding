/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doable.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:49:47 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:49:48 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	floodfill_exit(char **map, int x, int y, char wall)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == wall || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = 'X';
		return ;
	}
	map[y][x] = 'X';
	floodfill_exit(map, x + 1, y, wall);
	floodfill_exit(map, x - 1, y, wall);
	floodfill_exit(map, x, y + 1, wall);
	floodfill_exit(map, x, y - 1, wall);
}

static int	check_unreachables(char **map, t_data *data)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == data->content.collect)
				return (0);
	}
	return (1);
}

static int	check_exit_reachable(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'E')
				return (0);
	}
	return (1);
}

static int	setup_floodfill(t_data *data, char ***map_copy, int mode)
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
	if (mode == 0)
		floodfill_collect(*map_copy, px, py, data->content.wall);
	else
		floodfill_exit(*map_copy, px, py, data->content.wall);
	return (1);
}

int	is_doable(t_data *data)
{
	char	**map_collect;
	char	**map_exit;
	int		collect_ok;
	int		exit_ok;

	if (!setup_floodfill(data, &map_collect, 0))
		collect_ok = 0;
	else if (!check_unreachables(map_collect, data))
		collect_ok = 0;
	else
		collect_ok = 1;
	free_map_copy(map_collect);
	if (!setup_floodfill(data, &map_exit, 1) || !check_exit_reachable(map_exit))
		exit_ok = 0;
	else
		exit_ok = 1;
	free_map_copy(map_exit);
	return (collect_ok && exit_ok);
}
