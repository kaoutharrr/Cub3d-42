/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:37:23 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/18 15:31:52 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

int	move_east(t_vars *vars)
{
	vars->angle += 0.01;
	if (vars->angle < 0.0)
		vars->angle += 2 * M_PI;
	else if (vars->angle >= 2 * M_PI)
		vars->angle -= 2 * M_PI;
	return (0);
}

int	move_west(t_vars *vars)
{
	vars->angle -= 0.01;
	if (vars->angle < 0.0)
		vars->angle += 2 * M_PI;
	else if (vars->angle >= 2 * M_PI)
		vars->angle -= 2 * M_PI;
	return (0);
}
