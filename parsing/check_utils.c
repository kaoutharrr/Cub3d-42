/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 14:28:19 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:02:13 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	check_range(t_rgb *rgb)
{
	char	**ceiling;
	char	**floor;
	int		i;

	i = 0;
	ceiling = ft_split(rgb->ceiling, ',');
	floor = ft_split(rgb->floor, ',');
	while (ceiling[i])
	{
		if (ft_atoi(ceiling[i]) < 0 || ft_atoi(ceiling[i]) > 255)
			return (ft_free(floor), ft_free(ceiling), 1);
		i++;
	}
	i = 0;
	while (floor[i])
	{
		if (ft_atoi(floor[i]) < 0 || ft_atoi(floor[i]) > 255)
			return (ft_free(floor), ft_free(ceiling), 1);
		i++;
	}
	ft_free(ceiling);
	ft_free(floor);
	return (0);
}

int	is_identifier(char *c)
{
	if (!ft_strncmp(c, "SO", 2) || !ft_strncmp(c, "NO", 2)
		|| !ft_strncmp(c, "EA", 2) || !ft_strncmp(c, "WE", 2)
		|| !ft_strncmp(c, "F", 1) || !ft_strncmp(c, "C", 1))
		return (1);
	return (0);
}

int	find_map_start(t_game *game)
{
	int	i;
	int	j;
	int	map_start_index;

	i = 0;
	j = 0;
	map_start_index = 0;
	while (game->join[i])
	{
		j = 0;
		while (game->join[i][j] == ' ')
			j++;
		if (game->join[i][j] != '\0' && !is_identifier(&game->join[i][j])
			&& game->join[i][j] != '\n')
		{
			map_start_index = i;
			break ;
		}
		i++;
	}
	return (map_start_index);
}

int	check_symboles(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != ' ' && map[i][j] != 'N'
				&& map[i][j] != '\n' && map[i][j] != 'S'
				&& map[i][j] != 'E' && map[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	if (more_than_one(map))
		return (1);
	return (0);
}

int	check_player(char **map, t_player *player)
{
	if (map[player->p_y + 1][player->p_x] == ' '
		|| map[player->p_y - 1][player->p_x] == ' '
		|| map[player->p_y][player->p_x + 1] == ' '
		|| map[player->p_y][player->p_x - 1] == ' ')
		return (1);
	if (map[player->p_y + 1][player->p_x] == '\0'
		|| map[player->p_y - 1][player->p_x] == '\0'
		|| map[player->p_y][player->p_x + 1] == '\0'
		|| map[player->p_y][player->p_x - 1] == '\0')
		return (1);
	if (map[player->p_y + 1][player->p_x] == '\n'
		|| map[player->p_y - 1][player->p_x] == '\n'
		|| map[player->p_y][player->p_x + 1] == '\n'
		|| map[player->p_y][player->p_x - 1] == '\n')
		return (1);
	return (0);
}
