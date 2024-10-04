/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:28:42 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/18 13:43:08 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	ft_move( t_vars *vars)
{
	if (vars->rotate_east != -1)
		move_east(vars);
	else if (vars->rotate_west != -1)
		move_west(vars);
	if (vars->up != -1)
		move_up(vars);
	else if (vars->down != -1)
		move_down(vars);
	if (vars->go_west != -1)
		go_west(vars);
	else if (vars->go_east != -1)
		go_east(vars);
	mlx_destroy_image(vars->mlx, vars->img->imag);
	vars->img->imag = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	vars->img->addr = mlx_get_data_addr(vars->img->imag,
			&vars->img->bp, &vars->img->line_length, &vars->img->endian);
	send_rays(vars);
	return (0);
}

int	ft_down(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{	
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	if (keycode == 65363)
		vars->rotate_east = 65363;
	else if (keycode == 65361)
		vars->rotate_west = 65361;
	if (keycode == 65362 || keycode == 119)
		vars->up = 119;
	else if (keycode == 65364 || keycode == 115)
		vars->down = 115;
	if (keycode == 97)
		vars->go_west = 97;
	else if (keycode == 100)
		vars->go_east = 100;
	return (0);
}

int	ft_up( int keycode, t_vars *vars)
{
	if (keycode == 65363)
		vars->rotate_east = -1;
	else if (keycode == 65361)
		vars->rotate_west = -1;
	if (keycode == 65362 || keycode == 119)
		vars->up = -1;
	else if (keycode == 65364 || keycode == 115)
		vars->down = -1;
	if (keycode == 97)
		vars->go_west = -1;
	else if (keycode == 100)
		vars->go_east = -1;
	return (0);
}
