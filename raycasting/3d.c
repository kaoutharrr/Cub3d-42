/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:17:51 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 03:40:43 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

double	v_or_h(t_vars *vars)
{
	double	pos;

	pos = 0;
	if (vars->rays->flag == 'v')
		pos = (double)(fmod (vars->rays->v_y, 64) / 64) *vars->no.img_width;
	else
		pos = (double)(fmod(vars->rays->h_x, 64) / 64) *vars->no.img_width;
	return (pos);
}

void	init_flags(t_vars *vars)
{
	vars->rays->wall_start = 0;
	vars->rays->wall_end = 0;
	vars->rays->right = 0;
	vars->rays->left = 0;
	vars->rays->up = 0;
	vars->rays->right = 0;
}

int	where_he_is(t_vars *vars)
{
	if (vars->rays->flag == 'v')
	{
		if (vars->rays->right)
			return (RIGHT);
		else if (vars->rays->left)
			return (LEFT);
	}
	else if (vars->rays->flag == 'h')
	{
		if (vars->rays->up)
			return (UP);
		else if (vars->rays->down)
			return (DOWN);
	}
	return (0);
}
