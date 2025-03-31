#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/include/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}			t_img;

typedef struct cunt_s
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		count_p;
	int		count_e;
	int		count_c;
}			t_cunt;

typedef struct pos_s
{
	int		x;
	int		y;
}			t_pos;

typedef struct data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		width;
	int		height;
	char	**map;
	t_cunt	content;
	t_img	img;
	t_pos	pos;
	int		count;
}			t_data;
void		ft_error(char *str, int i);
int			ft_same_char(char *str);

int			ft_same_char(char *str);
int			map_height(char **map);
char		**duplicate_map(char **map);
void		free_map_copy(char **map);
int			find_player_pos(char **map, int *x, int *y);
char		*get_map(int fd);
char		**map_core(char **str, t_data *data);
int			chk_map(char **argv);
int			is_doable(t_data *data);

int			ft_check_col(char *map_line, char col, t_data *data);
int			ft_check_line(char *map_line, char wall);
int			ft_check_other(char *map_line, t_cunt *content);
void		ft_check_content(t_data *data);
int			ft_check_format(char **map);
int			chk_collect(t_data *data);

void		set_img(t_data *data);
void		set_content(t_cunt *content);

void		core_render(t_data *data);
int			render(t_data *data);
void		render_other(t_data *data);
void		render_background(t_data *data);
void		render_down(t_data *data);
void		render_left(t_data *data);
void		render_right(t_data *data);
void		render_top(t_data *data);
void		print_img(t_data *data, void *img, int x, int y);

int			key_press(int keysym, t_data *data);
int			chk_collect(t_data *data);
int			end(t_data *data);

#endif
