/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:58:54 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:37:21 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>

typedef struct s_c_color{
	int	red;
	int	green;
	int	blue;
}	t_c_color;

typedef struct s_f_color{
	int	red;
	int	green;
	int	blue;
}	t_f_color;

typedef struct s_colors{
	t_c_color		c_color;
	t_f_color		f_color;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
}	t_colors;

typedef struct s_rgb{
	char	*ceiling;
	char	*floor;
}	t_rgb;

typedef struct s_textures{
	char	*no;
	char	*so;
	char	*ea;
	char	*we;
	t_rgb	rgb;
}	t_textures;

typedef struct t_texture_data{
	char	*name;
}	t_texture_data;

typedef struct t_player{
	int	p_x;
	int	p_y;
}	t_player;

typedef struct s_game{
	char			**file;
	char			**map;
	char			**join;
	char			**kaouthar_map;
	t_textures		textures;
	t_colors		colors;
	int				map_height;
	int				map_width;
	int				file_len;
}	t_game;

void			print_error(char *error, int exit_code);
void			ft_free(char **arr);
void			find_player_pos(char **map, t_player *player);
void			free_names(t_texture_data *textures, int nums_textures);
void			free_textures(t_game *game);
void			find_player_pos(char **map, t_player *player);
int				parse_settings(t_game *game);
int				check_map_name(char *map_name);
int				longest_line_raycast(char **map);
int				open_file(char *path, t_game *game);
int				get_map(char *file_path, t_game *game);
int				check_settings(t_game *game);
int				check_range(t_rgb *rgb);
int				map_width(char *map);
int				map_lenght_check(char **file);
int				check_map_valid(t_game *game);
int				find_map_start(t_game *game);
int				check_symboles(char **map);
int				more_than_one(char **map);
int				longest_line(t_game *game);
int				fill_map(t_game *game);
int				check_player(char **map, t_player *player);
int				check_first_index(char **map);
int				check_new_line(char **map);
int				is_empty(const char *line);
int				size_of_array(char **arr);
int				map_lenght(char **file);
int				ft_count_lines(char *path);
int				check_texture(char **texture, t_game *game);
unsigned int	rgb_coverter(t_colors *color, int flag);
void			parse_call(t_game *game, t_texture_data *textures,
					int num_textures);
#	endif
