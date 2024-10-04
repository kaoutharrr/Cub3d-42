/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_norm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 03:06:09 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:37:28 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	check_texture(char **texture, t_game *game)
{
	if (ft_strncmp(texture[0], "NO", 3) == 0)
		game->textures.no = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "EA", 3) == 0)
		game->textures.ea = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "SO", 3) == 0)
		game->textures.so = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "WE", 3) == 0)
		game->textures.we = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "C", 2) == 0)
		game->textures.rgb.ceiling = ft_strdup(texture[1]);
	else if (ft_strncmp(texture[0], "F", 2) == 0)
		game->textures.rgb.floor = ft_strdup(texture[1]);
	else
		return (1);
	return (0);
}

void	find_player_pos(char **map, t_player *player)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S'
			|| map[i][j] == 'E')
			{
				player->p_x = j;
				player->p_y = i;
			}
			j++;
		}
		i++;
	}
}

void	parse_call(t_game *game, t_texture_data *textures, int num_textures)
{
	free_names(textures, num_textures);
	if (!game->textures.ea || !game->textures.no || !game->textures.so
		|| !game->textures.we || !game->textures.rgb.ceiling
		|| !game->textures.rgb.floor)
		print_error("Error: Bad parameters\n", 2);
}
