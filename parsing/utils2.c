/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:19:17 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:14:04 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

void	free_names(t_texture_data *textures, int nums_textures)
{
	int	i;

	i = 0;
	while (nums_textures > i)
	{
		free(textures[i].name);
		i++;
	}
}

int	size_of_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	print_error(char *error, int exit_code)
{
	ft_putstr_fd(error, 2);
	exit(exit_code);
}

void	free_textures(t_game *game)
{
	if (game->textures.no)
		free(game->textures.no);
	if (game->textures.so)
		free(game->textures.so);
	if (game->textures.we)
		free(game->textures.we);
	if (game->textures.ea)
		free(game->textures.ea);
	if (game->textures.rgb.floor)
		free(game->textures.rgb.floor);
	if (game->textures.rgb.ceiling)
		free(game->textures.rgb.ceiling);
}

int	ft_count_lines(char *path)
{
	int		count;
	char	*line;
	int		fd;

	fd = open(path, O_RDWR);
	line = "";
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		count++;
		free(line);
	}
	return (count);
}
