/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:50:06 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:50:07 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	**parse_map(int fd, t_data *data)
{
	int		i;
	char	*temp;

	i = 1;
	temp = get_map(fd);
	data->map = ft_split(temp, '\n');
	free(temp);
	ft_check_content(data);
	if (!(ft_check_format(data->map)))
		return (ft_free_map(data));
	if (!(ft_check_line(data->map[0], data->content.wall)))
		return (ft_free_map(data));
	while (data->map[i] != NULL)
	{
		if (!(ft_check_col(data->map[i], data->content.wall, data)))
			return (ft_free_map(data));
		else if (!(ft_check_other(data->map[i], &(data->content))))
			return (ft_free_map(data));
		i++;
	}
	data->height = i;
	if (!(ft_check_line(data->map[i - 1], data->content.wall)))
		return (ft_free_map(data));
	return (data->map);
}

static void	core_helper(t_data *data, int fd)
{
	if (fd > 0)
		data->map = parse_map(fd, data);
	else
		ft_error("Failed to open file", 1);
	if ((data->content.count_c == 0 || data->content.count_e != 1
			|| data->content.count_p != 1) && data->map != NULL)
	{
		ft_free_map(data);
		ft_error("Need 1 Player/Exit and at least 1 Object", 1);
	}
	if (!is_doable(data))
	{
		ft_free_map(data);
		ft_error("Map is not solvable", 1);
	}
}

char	*lastslash(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	while (i >= 0 && s[i] != '/')
		i--;
	if (i >= 0)
		return (&s[i]);
	else
		return (NULL);
}

char	**map_core(char **str, t_data *data)
{
	int		fd;
	char	*dot_pos;
	char	*filename;

	data->map = NULL;
	if (lastslash(str[1]))
		filename = lastslash(str[1]) + 1;
	else
		filename = str[1];
	dot_pos = ft_strrchr(filename, '.');
	if (!dot_pos || ft_strlen(dot_pos) != 4 || ft_strncmp(dot_pos, ".ber",
			ft_strlen(dot_pos)) != 0 || ft_strlen(filename) == 4)
	{
		ft_error("No correct format map found", 1);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error("Failed to open file", 1);
	}
	core_helper(data, fd);
	return (data->map);
}
