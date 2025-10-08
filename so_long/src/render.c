/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:50:42 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:50:43 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == data->content.wall)
				print_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == data->content.space)
				print_img(data, data->img.img_floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	render_other(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->content.collect)
				print_img(data, data->img.img_collect, x, y);
			if (data->map[y][x] == data->content.exit)
				print_img(data, data->img.img_exit, x, y);
			if (data->map[y][x] == data->content.player)
			{
				data->pos.x = x * data->img.width;
				data->pos.y = y * data->img.height;
				print_img(data, data->img.img_player, x, y);
			}
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	render_background(data);
	render_other(data);
	return (0);
}

void	core_render(t_data *data)
{
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			(data->width * data->img.width),
			(data->height * data->img.height), "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyRelease, KeyReleaseMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}

void	print_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}
