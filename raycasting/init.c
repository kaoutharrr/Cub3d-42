/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:58:22 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 03:57:12 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

void	start_game(t_game game)
{
	t_vars	*vars;

	vars = ft_init(game);
	get_angle(vars);
	find_player(vars);
	init_flags(vars);
	init_tex(vars);
	send_rays(vars);
	mlx_hook(vars->win, 17, 0L, (void *)exit, vars);
	mlx_hook(vars->win, 02, 1L << 0, ft_down, vars);
	mlx_hook(vars->win, 03, 1L << 1, ft_up, vars);
	mlx_loop_hook(vars->mlx, ft_move, vars);
	mlx_loop(vars->mlx);
}

t_vars	*ft_init(t_game game)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	vars->img = malloc(sizeof(t_img));
	vars->rays = malloc(sizeof(t_rays));
	vars->map = game.kaouthar_map;
	vars->ceiling_color = game.colors.ceiling_color;
	vars->floor_color = game.colors.floor_color;
	vars->fov = M_PI / 3;
	vars->down = -1;
	vars->up = -1;
	vars->game = game;
	vars->rotate_east = -1;
	vars->rotate_west = -1;
	vars->width = game.map_width;
	vars->height = game.map_height;
	vars->go_east = -1;
	vars->go_west = -1;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "cuuuuub<3");
	vars->img->imag = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->imag,
			&vars->img->bp, &vars->img->line_length, &vars->img->endian);
	return (vars);
}

void	init_tex(t_vars *vars)
{
	vars->no.img = mlx_xpm_file_to_image(vars->mlx, vars->game.textures.no,
			&vars->no.img_width, &vars->no.img_height);
	vars->so.img = mlx_xpm_file_to_image(vars->mlx, vars->game.textures.so,
			&vars->so.img_width, &vars->so.img_height);
	vars->ea.img = mlx_xpm_file_to_image(vars->mlx, vars->game.textures.ea,
			&vars->ea.img_width, &vars->ea.img_height);
	vars->we.img = mlx_xpm_file_to_image(vars->mlx, vars->game.textures.we,
			&vars->we.img_width, &vars->we.img_height);
	if (!vars->no.img || !vars->so.img || !vars->ea.img || !vars->we.img)
		print_error("Error: Wrong textures\n", 2);
	vars->no.addr = mlx_get_data_addr(vars->no.img, &vars->no.bits,
			&vars->no.len, &vars->no.end);
	vars->so.addr = mlx_get_data_addr(vars->so.img, &vars->so.bits,
			&vars->so.len, &vars->so.end);
	vars->ea.addr = mlx_get_data_addr(vars->ea.img, &vars->ea.bits,
			&vars->ea.len, &vars->ea.end);
	vars->we.addr = mlx_get_data_addr(vars->we.img, &vars->we.bits,
			&vars->we.len, &vars->we.end);
	if (!vars->no.addr || !vars->so.addr || !vars->ea.addr || !vars->we.addr)
		print_error("Error: Wrong textures\n", 2);
}

void	get_angle(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N')
				vars->angle = (3 * M_PI) / 2;
			if (vars->map[i][j] == 'S')
				vars->angle = M_PI / 2;
			if (vars->map[i][j] == 'E')
				vars->angle = 0;
			if (vars->map[i][j] == 'W')
				vars->angle = M_PI ;
			j++;
		}
		i++;
	}
}

void	find_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			if (vars->map[i][j] == 'N' || vars->map[i][j] == 'S'
				|| vars->map[i][j] == 'E' || vars->map[i][j] == 'W')
			{
				vars->x = (j * 64) + 32 ;
				vars->y = (i * 64) + 32;
				return ;
			}
			else
				j++;
		}
		i++;
	}
}
