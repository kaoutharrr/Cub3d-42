/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:17:05 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 04:01:36 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"game.h"

int	protection(int y, int x, t_vars *vars)
{
	if (x < 0 || x >= (vars->width) * 64)
		return (0);
	if (y < 0 || y >= (vars->height) * 64)
		return (0);
	if (vars->map[y / 64][x / 64] == '1')
		return (0);
	return (1);
}

int	walls_stop(t_vars *vars, int x, int y)
{
	if (x < 0 || x / 64 > vars->width || y < 0 || y / 64 > vars->height)
		return (1);
	if (vars->map[y / 64][x / 64] == '1')
		return (1);
	if (vars->map[y / 64][(x + 3) / 64] == '1')
		return (1);
	if (vars->map[y / 64][(x - 3) / 64] == '1')
		return (1);
	if (vars->map[(y - 3) / 64][x / 64] == '1')
		return (1);
	if (vars->map[(y + 3) / 64][x / 64] == '1')
		return (1);
	if (vars->map[(y + 3) / 64][(x + 3) / 64] == '1')
		return (1);
	if (vars->map[(y - 3) / 64][(x + 3) / 64] == '1')
		return (1);
	if (vars->map[(y + 3) / 64][(x - 3) / 64] == '1')
		return (1);
	if (vars->map[(y - 3) / 64][(x - 3) / 64] == '1')
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return ;
	dst = vars->img->addr + (y * vars->img->line_length
			+ x * (vars->img->bp / 8));
	*(unsigned int *)dst = color;
}
