

#include "../includes/so_long.h"

void	render_top(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("You won in %d moves! Are you proud of yourself? \n", data->count);
				end(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("You won in %d moves! Arr you proud of yourself? \n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("You won in %d moves! Arre you proud of yourself? \n",
					data->count);
				end(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	int		pos_x;
	int		pos_y;

	pos_x = data->pos.x / data->img.height;
	pos_y = data->pos.y / data->img.width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.space;
			data->count += 1;
			printf("count: %d\n", data->count);
		}
		else
		{
			if (chk_collect(data) == 0)
			{
				printf("You won in %d moves! Arrbys you proud of yourself? \n",
					data->count);
				end(data);
			}
		}
	}
}
