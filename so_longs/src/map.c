#include "../includes/so_long.h"

char	*get_map(int fd)
{
	char	*line_map;
	char	*buff;
	char	*tmp_buff;

	buff = ft_strdup("");
	if (!buff)
		ft_error("Memory allocation failed", 1);
	line_map = get_next_line(fd);
	if (!line_map)
	{
		free(buff);
		ft_error("Map is empty", 1);
	}
	while (line_map)
	{
		tmp_buff = buff;
		buff = ft_strjoin(tmp_buff, line_map);
		free(tmp_buff);
		free(line_map);
		if (!buff)
			ft_error("Memory allocation failed", 1);
		line_map = get_next_line(fd);
	}
	return (buff);
}

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
	int	i;

	i = 1;
	data->map = ft_split(get_map(fd), '\n');
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

char	**map_core(char **str, t_data *data)
{
	int	fd;

	data->map = NULL;
	if (!(ft_strrchr(str[1], '.')) || ft_strncmp(ft_strrchr(str[1], '.'),
			".ber", ft_strlen(ft_strrchr(str[1], '.'))) != 0)
		ft_error("No correct format map found", 1);
	fd = open(str[1], O_RDONLY);
	core_helper(data, fd);
	return (data->map);
}
