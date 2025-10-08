/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:50:35 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:50:37 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.space;
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->count += 1;
			printf("\033[1;33mMoves: %d\033[0m\n", data->count);
		}
		else
		{
			if (collect_check(data) == 0)
			{
				printf("\033[1;32mYou won in %d Moves!\033[0m\n", data->count);
				end(data);
			}
		}
	}
}

void	move_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.space;
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->count += 1;
			printf("\033[1;33mMoves: %d\033[0m\n", data->count);
		}
		else
		{
			if (collect_check(data) == 0)
			{
				printf("\033[1;32mYou won in %d Moves!\033[0m\n", data->count);
				end(data);
			}
		}
	}
}

void	move_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.space;
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->count += 1;
			printf("\033[1;33mMoves: %d\033[0m\n", data->count);
		}
		else
		{
			if (collect_check(data) == 0)
			{
				printf("\033[1;32mYou won in %d Moves!\033[0m\n", data->count);
				end(data);
			}
		}
	}
}

void	move_down(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y][pos_x] = data->content.space;
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->count += 1;
			printf("\033[1;33mMoves: %d\033[0m\n", data->count);
		}
		else
		{
			if (collect_check(data) == 0)
			{
				printf("\033[1;32mYou won in %d Moves!\033[0m\n", data->count);
				end(data);
			}
		}
	}
}

int	key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	if (keysym == XK_w || keysym == XK_Up)
		move_up(data);
	if (keysym == XK_d || keysym == XK_Right)
		move_right(data);
	if (keysym == XK_a || keysym == XK_Left)
		move_left(data);
	if (keysym == XK_s || keysym == XK_Down)
		move_down(data);
	return (0);
}
