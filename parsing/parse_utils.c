/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:12:50 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:18:29 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	longest_line(t_game *game)
{
	int	i;
	int	max;

	i = find_map_start(game);
	if (game->join)
		max = ft_strlen(game->join[i]);
	while (game->join[i])
	{
		if (ft_strlen(game->join[i]) > max)
			max = ft_strlen(game->join[i]);
		i++;
	}
	return (max);
}

int	longest_line_raycast(char **map)
{
	int	i;
	int	max;

	i = 0;
	if (map)
		max = ft_strlen(map[i]);
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

int	is_empty(const char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	fill_map(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = find_map_start(game);
	j = 0;
	k = 1;
	game->map = ft_calloc ((map_lenght_check(game->join) - i + 3),
			sizeof (char *));
	if (!game->map)
		return (1);
	game->map[0] = ft_calloc(longest_line(game) + 1, sizeof(char));
	while (game->join[i])
	{
		game->map[k] = ft_calloc(longest_line(game) + 1, sizeof (char));
		ft_strlcpy(game->map[k], game->join[i], ft_strlen(game->join[i]) + 1);
		i++;
		k++;
	}
	game->map[k] = ft_calloc(longest_line(game) + 1, sizeof (char));
	game->map[k + 1] = NULL;
	return (0);
}

int	check_first_index(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		if (map[i][0] != '1' && map[i][0] != ' ' && map[i][0] != '\0')
			return (1);
		i++;
	}
	return (0);
}
