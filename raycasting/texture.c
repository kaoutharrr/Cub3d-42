/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 01:29:19 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 04:00:35 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	render_textures(t_vars *vars, int i, int j, t_text *texture)
{
	int				x;
	int				y;
	unsigned int	color;
	char			*newadd;
	char			*dst;

	dst = NULL;
	y = (float)((float)(j - vars->rays->wall_start) / vars->rays->wall_size)
		*texture->img_height;
	x = v_or_h(vars);
	if (x < 0 || x >= texture->img_width || y < 0 || y >= texture->img_height)
		return ;
	newadd = texture->addr + (y * texture->len + x * (texture->bits / 8));
	color = *(unsigned int *)newadd;
	dst = vars->img->addr + (j * vars->img->line_length + i
			*(vars->img->bp / 8));
	*(unsigned int *)dst = color;
}

void	draw_wall(t_vars *vars, double dis, int i)
{
	int	j;

	vars->rays->wall_start = (HEIGHT - dis) / 2;
	vars->rays->wall_end = (HEIGHT / 2) + (dis / 2);
	j = 0;
	get_direction(vars);
	while (j < HEIGHT)
	{
		if (j >= vars->rays->wall_start && j < vars->rays->wall_end)
		{
			if (where_he_is(vars) == UP)
				render_textures(vars, i, j, &vars->no);
			else if (where_he_is(vars) == DOWN)
				render_textures(vars, i, j, &vars->so);
			else if (where_he_is(vars) == LEFT)
				render_textures(vars, i, j, &vars->we);
			else if (where_he_is(vars) == RIGHT)
				render_textures(vars, i, j, &vars->ea);
		}
		else if (j <= HEIGHT / 2)
			my_mlx_pixel_put(vars, i, j, vars->ceiling_color);
		else
			my_mlx_pixel_put(vars, i, j, vars->floor_color);
		j++;
	}
}

void	get_direction(t_vars *vars)
{
	double	angle;

	vars->rays->wall_size = vars->rays->wall_end - vars->rays->wall_start;
	angle = vars->rays->ray_angle;
	if (angle >= 0 && angle <= M_PI)
		first_half(vars, angle);
	else if (angle >= (M_PI) && angle <= (3 * M_PI) / 2)
	{
		vars->rays->up = 1;
		vars->rays->left = 1;
		vars->rays->down = 0;
		vars->rays->right = 0;
	}
	else if (angle >= (3 * M_PI) / 2 && angle <= 2 * M_PI)
	{
		vars->rays->up = 1;
		vars->rays->right = 1;
		vars->rays->down = 0;
		vars->rays->left = 0;
	}
}

void	first_half(t_vars *vars, double angle)
{
	if (angle >= 0 && angle <= (M_PI / 2))
	{
		vars->rays->down = 1;
		vars->rays->right = 1;
		vars->rays->up = 0;
		vars->rays->left = 0;
	}
	else if (angle >= (M_PI / 2) && angle <= M_PI)
	{
		vars->rays->down = 1;
		vars->rays->left = 1;
		vars->rays->up = 0;
		vars->rays->right = 0;
	}
}
