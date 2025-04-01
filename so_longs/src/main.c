#include "../includes/so_long.h"

int	collect_check(t_data *data)
{
	int		i;
	int		y;
	int		count;

	i = 0;
	y = 0;
	count = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collect)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);
}

int	end(t_data *data)
{
	int		i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
	}
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
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

void	ft_error(char *str, int i)
{
	ft_printf("Error\n%s\n", str);
	exit(i);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_error("You need to select a map of type .ber", 1);
	}
	else
	{
		data.count = 0;
		data.mlx_ptr = mlx_init();
		set_content(&(data.content));
		data.map = map_core(argv, &data);
		if (data.map != NULL)
		{
			set_img(&data);
			core_render(&data);
		}
		else
			end(&data);
	}
	return (0);
}
