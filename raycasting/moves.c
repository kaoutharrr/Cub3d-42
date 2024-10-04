/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 21:06:58 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 04:34:55 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

int	move_up(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->y + (1.5 * sin(vars->angle));
	x = vars->x + (1.5 * cos(vars->angle));
	if (!walls_stop(vars, x, y))
	{
		vars->x += (1.5 * cos(vars->angle));
		vars->y += (1.5 * sin(vars->angle));
	}
	return (0);
}

int	move_down(t_vars *vars)
{
	int	x;
	int	y;

	y = vars->y - (1.5 * sin(vars->angle));
	x = vars->x - (1.5 * cos(vars->angle));
	if (! walls_stop(vars, x, y))
	{
		vars->y -= (1.5 * sin(vars->angle));
		vars->x -= (1.5 * cos(vars->angle));
	}
	return (0);
}

int	go_west(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x + (1.2 * sin(vars->angle));
	y = vars->y - (1.2 * cos(vars->angle));
	if (! walls_stop(vars, x, y))
	{
		vars->x += (1.2 * sin(vars->angle));
		vars->y -= (1.2 * cos(vars->angle));
	}
	return (0);
}

int	go_east(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->x - (1.2 * sin(vars->angle));
	y = vars->y + (1.2 * cos(vars->angle));
	if (!walls_stop(vars, x, y))
	{
		vars->x -= (1.2 * sin(vars->angle));
		vars->y += (1.2 * cos(vars->angle));
	}
	return (0);
}
