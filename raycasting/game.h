/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:51:09 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 03:59:01 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include"../parsing/cub3d.h"
# include <math.h>
# include <mlx.h>

# define PURPLE 0x581845
# define PINK 0xC70039
# define YELLOW 0xFFC300
# define RED 0x7F0622
# define CUTE_BLUE 0x213555
# define KHZI_HH 0x264643
# define BLUE 0x4F709C
# define WHITE 0x4F709C
# define BLACK 0x000000
# define WIDTH 1280
# define HEIGHT 720
# define LEFT 22
# define RIGHT 33
# define UP 44
# define DOWN 55

typedef struct t_img {
	void	*imag;
	char	*addr;
	int		bp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct t_rays
{
	double	ray_angle;
	double	h_x;
	double	h_y;
	double	v_x;
	double	v_y;
	double	d_h_x;
	double	d_h_y;
	double	d_v_x;
	double	d_v_y;
	int		r_x;
	int		r_y;
	int		flag;
	int		up;
	int		down;
	int		right;
	int		left;
	int		wall_start;
	int		wall_end;
	int		wall_size;
}	t_rays;

typedef struct s_text{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		len;
	int		bits;
	int		end;
}	t_text;
typedef struct t_vars
{
	char			**map;
	void			*mlx;
	void			*win;
	double			angle;
	t_game			game;
	double			fov;
	double			ray;
	double			x;
	double			y;
	int				height;
	int				width;
	int				rotate_east;
	int				rotate_west;
	int				go_east;
	int				go_west;
	int				up;
	int				down;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	t_img			*img;
	t_rays			*rays;
	t_text			no;
	t_text			ea;
	t_text			we;
	t_text			so;
}	t_vars;

void	find_player(t_vars *vars);
t_vars	*ft_init(t_game game);
void	start_game(t_game game);
void	get_angle(t_vars *vars);
void	draw_map(t_vars *vars);
void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void	send_rays(t_vars *vars);
int		ft_move( t_vars *vars);
int		ft_down(int keycode, t_vars *vars);
int		ft_up( int keycode, t_vars *vars);
int		protection(int y, int x, t_vars *vars);
void	first(t_vars *vars);
double	distance(t_vars *vars);
void	draw_distance(t_vars *vars, double distance, int i);
void	second(t_vars *vars);
void	angle_reset(double angle);
void	draw_line(t_vars *vars, double x, double y);
void	map_2d(t_vars *vars);
void	draw_square(t_vars *vars, double x, double y, int color);
void	draw_square1(t_vars *vars, double x, double y);
void	draw_pixel(t_vars *data, double x, double y, double color);
int		move_east(t_vars *vars);
int		move_west(t_vars *vars);
int		move_up(t_vars *vars);
int		move_down(t_vars *vars);
int		go_west(t_vars *vars);
int		go_east(t_vars *vars);
int		ft_down(int keycode, t_vars *vars);
int		ft_up( int keycode, t_vars *vars);
int		check_map_name(char *map_name);
int		get_map(char *file_path, t_game *game);
int		walls_stop(t_vars *vars, int x, int y);
void	ft_line(t_vars *vars, double x, double y, double dis);
void	first(t_vars *vars);
void	second(t_vars *vars);
void	third(t_vars *vars);
void	last(t_vars *vars);
void	draw_3d(t_vars *vars);
void	draw_wall(t_vars *vars, double dis, int i);
void	cases(t_vars *vars);
void	init_flags(t_vars *vars);
double	v_or_h(t_vars *vars);
void	render_textures(t_vars *vars, int i, int j, t_text *texture);
int		where_he_is(t_vars *vars);
void	init_tex(t_vars *vars);
void	get_direction(t_vars *vars);
void	first_half(t_vars *vars, double angle);
#	endif
