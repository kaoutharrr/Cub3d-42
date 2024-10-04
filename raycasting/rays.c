/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 03:50:13 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/18 14:01:38 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	first(t_vars *vars)
{
	double	angle;

	angle = vars->rays->ray_angle;
	vars->rays->h_y = (floor(vars->y / 64) * 64) - 0.0001;
	vars->rays->h_x = vars->x - ((vars->y - vars->rays->h_y)) / tan(angle);
	vars->rays->v_x = (floor(vars->x / 64) * 64) - 0.0001;
	vars->rays->v_y = vars->y - (((vars->x - vars->rays->v_x)) * (tan(angle)));
	vars->rays->d_h_y = -64 ;
	vars->rays->d_h_x = -64 / tan(angle);
	vars->rays->d_v_x = -64 ;
	vars->rays->d_v_y = -64 * tan(angle);
}

void	second(t_vars *vars)
{
	double	angle;

	angle = vars->rays->ray_angle;
	vars->rays->h_y = (floor(vars->y / 64) * 64) - 0.0001;
	vars->rays->h_x = vars->x - ((vars->y - vars->rays->h_y) / tan(angle));
	vars->rays->v_x = (floor(vars->x / 64) * 64) + 64;
	vars->rays->v_y = vars->y + ((fabs(vars->x - vars->rays->v_x))
			* tan(angle));
	vars->rays->d_h_y = -64;
	vars->rays->d_h_x = -64 / tan(angle);
	vars->rays->d_v_x = 64 ;
	vars->rays->d_v_y = tan(angle) * 64;
}

void	third(t_vars *vars)
{
	double	angle;

	angle = vars->rays->ray_angle;
	vars->rays->h_y = (floor(vars->y / 64) * 64) + 64;
	vars->rays->h_x = vars->x + (fabs(vars->rays->h_y - vars->y)) / tan(angle);
	vars->rays->v_x = (floor(vars->x / 64) * 64) - 0.0001;
	vars->rays->v_y = (vars->y - (((vars->x - vars->rays->v_x)) * tan(angle)));
	vars->rays->d_h_y = 64;
	vars->rays->d_h_x = 64 / tan(angle);
	vars->rays->d_v_x = -64;
	vars->rays->d_v_y = - (64 * tan(angle));
}

void	last(t_vars *vars)
{
	double	angle;

	angle = vars->rays->ray_angle;
	vars->rays->h_y = (floor(vars->y / 64) * 64) + 64;
	vars->rays->h_x = vars->x + ((fabs(vars->rays->h_y - vars->y))
			* (1 / tan(angle)));
	vars->rays->v_x = (floor(vars->x / 64) * 64) + 64;
	vars->rays->v_y = (vars->y + ((fabs(vars->x - vars->rays->v_x))
				* (tan(angle))));
	vars->rays->d_h_y = 64;
	vars->rays->d_h_x = 64 / tan(angle);
	vars->rays->d_v_x = 64;
	vars->rays->d_v_y = 64 * tan(angle);
}
