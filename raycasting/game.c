/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:55:39 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 03:41:04 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

void	send_rays(t_vars *vars)
{
	int		i;
	double	a;
	double	d3;
	double	final_dis;
	double	dis;

	i = 0;
	a = (M_PI / 3) / WIDTH;
	vars->rays->ray_angle = vars->angle - (M_PI / 6);
	while (i < WIDTH)
	{
		cases(vars);
		dis = distance(vars);
		final_dis = cos(vars->rays->ray_angle - vars->angle) * dis;
		d3 = (64 / final_dis) * 977;
		draw_wall(vars, d3, i);
		i++;
		vars->rays->ray_angle += a;
	}
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->imag, 0, 0);
}

double	distance(t_vars *vars)
{
	double	h_distance;
	double	v_distance;

	while (protection(vars->rays->h_y, vars->rays->h_x, vars))
	{
		vars->rays->h_x += vars->rays->d_h_x;
		vars->rays->h_y += vars->rays->d_h_y;
	}
	while (protection(vars->rays->v_y, vars->rays->v_x, vars))
	{
		vars->rays->v_x += vars->rays->d_v_x;
		vars->rays->v_y += vars->rays->d_v_y;
	}
	h_distance = sqrt(pow(vars->y - vars->rays->h_y, 2)
			+ pow(vars->x - vars->rays->h_x, 2));
	v_distance = sqrt(pow(vars->y - vars->rays->v_y, 2)
			+ pow(vars->x - vars->rays->v_x, 2));
	if (h_distance < v_distance)
	{
		vars->rays->flag = 'h';
		return (h_distance);
	}
	vars->rays->flag = 'v';
	return (v_distance);
}

void	cases(t_vars *vars)
{
	if (vars->rays->ray_angle < 0.0)
		vars->rays->ray_angle += (2 * M_PI);
	else if (vars->rays->ray_angle >= 2 * M_PI)
		vars->rays->ray_angle -= (2 * M_PI);
	if (vars->rays->ray_angle >= 0 && vars->rays->ray_angle <= M_PI / 2)
		last(vars);
	else if (vars->rays->ray_angle >= M_PI / 2 && vars->rays->ray_angle <= M_PI)
		third(vars);
	else if (vars->rays->ray_angle <= (2 * M_PI)
		&& vars->rays->ray_angle >= (3 * M_PI / 2))
		second(vars);
	else if (vars->rays->ray_angle <= (3 * M_PI / 2)
		&& vars->rays->ray_angle >= (M_PI))
		first(vars);
}
