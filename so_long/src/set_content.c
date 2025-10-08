/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:51:05 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:51:06 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_cunt *content)
{
	content->exit = 'E';
	content->player = 'P';
	content->wall = '1';
	content->space = '0';
	content->collect = 'C';
	content->count_p = 0;
	content->count_e = 0;
	content->count_c = 0;
}

static int	file_exists(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

void	put_img(t_data *data)
{
	if (!file_exists(data->img.wall))
		ft_error("wall texture file missing", 1);
	else
		data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.wall, &(data->img.width), &(data->img.height));
	if (!file_exists(data->img.floor))
		ft_error("floor texture file missing", 1);
	else
		data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.floor, &(data->img.width), &(data->img.height));
	if (!file_exists(data->img.exit))
		ft_error("exit texture file missing", 1);
	else
		data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.exit, &(data->img.width), &(data->img.height));
	if (!file_exists(data->img.collect))
		ft_error("collect texture file missing", 1);
	else
		data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.collect, &(data->img.width), &(data->img.height));
	if (!file_exists(data->img.player))
		ft_error("player texture file missing", 1);
	else
		data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
				data->img.player, &(data->img.width), &(data->img.height));
}

void	set_img(t_data *data)
{
	data->img.floor = "./textures/floor.xpm";
	data->img.wall = "./textures/wall.xpm";
	data->img.collect = "./textures/collect.xpm";
	data->img.player = "./textures/player.xpm";
	data->img.exit = "./textures/exit.xpm";
	put_img(data);
}
