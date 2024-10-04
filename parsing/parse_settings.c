/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:31:46 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:36:16 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	fill_textures(char *str, t_game *game)
{
	int		i;
	char	**texture;

	texture = ft_split(str, ' ');
	i = size_of_array(texture);
	if (i == 2)
	{
		if (check_texture(texture, game))
			return (ft_free(texture), 1);
	}
	else
		return (ft_free(texture), 1);
	return (ft_free(texture), 0);
}

int	is_duplicate_texture(t_texture_data *textures, int num_textures, char *name)
{
	int	i;

	i = 0;
	while (i < num_textures)
	{
		if (ft_strncmp(textures[i].name, name, 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_texture(char *c)
{
	if (!ft_strncmp(c, "SO", 2) || !ft_strncmp(c, "NO", 2)
		|| !ft_strncmp(c, "EA", 2) || !ft_strncmp(c, "WE", 2)
		|| !ft_strncmp(c, "F", 1) || !ft_strncmp(c, "C", 1))
		return (1);
	return (0);
}

static void	init_textures(t_game *game)
{
	game->textures.no = NULL;
	game->textures.so = NULL;
	game->textures.we = NULL;
	game->textures.ea = NULL;
	game->textures.rgb.floor = NULL;
	game->textures.rgb.ceiling = NULL;
}

int	parse_settings(t_game *game)
{
	int				i;
	int				j;
	int				num_textures;
	t_texture_data	textures[6];

	num_textures = 0;
	i = 0;
	init_textures(game);
	while (game->file[i])
	{
		j = 0;
		while (game->file[i][j] == ' ' || game->file[i][j] == '\t')
			j++;
		if (is_texture(&game->file[i][j]))
		{
			if (is_duplicate_texture(textures, num_textures, game->file[i] + j)
				|| fill_textures(game->file[i], game))
				return (free_names(textures, num_textures), 1);
			textures[num_textures].name = ft_strdup(game->file[i] + j);
			num_textures++;
		}
		i++;
	}
	parse_call(game, textures, num_textures);
	return (0);
}
