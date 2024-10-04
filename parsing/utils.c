/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:12:40 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/17 22:23:51 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	map_lenght_check(char **file)
{
	int	count;

	count = 1;
	while (file[count])
		count++;
	return (count);
}

int	map_lenght(char **file)
{
	int	count;

	count = 0;
	while (file[count])
		count++;
	return (count);
}

unsigned int	rgb_coverter(t_colors *color, int flag)
{
	int	result;

	if (flag == 1)
		result = (color->c_color.red << 16) | (color->c_color.green << 8)
			| (color->c_color.blue);
	else
		result = (color->f_color.red << 16) | (color->f_color.green << 8)
			| (color->f_color.blue);
	return (result);
}

void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

int	more_than_one(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	j = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S'
				|| map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		print_error("Error: Duplicated player symbole\n", 1);
	if (count == 0)
		print_error("Error: Need one player\n", 1);
	return (0);
}
