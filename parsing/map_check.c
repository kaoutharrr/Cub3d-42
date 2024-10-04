/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 14:35:55 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/17 22:23:42 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "./cub3d.h"

int	is_false(char c)
{
	if (c == ' ' || c == '\n' || c == '\0')
		return (1);
	return (0);
}

int	check_everything(char **map)
{
	int			i;
	int			j;
	t_player	player;

	i = 1;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (is_false(map[i][j - 1]) || is_false(map[i][j + 1])
					|| is_false(map[i - 1][j]) || is_false(map[i + 1][j]))
					return (1);
			}
			j++;
		}
		i++;
	}
	find_player_pos(map, &player);
	if (check_player(map, &player))
		return (1);
	return (0);
}

int	check_first_wall(t_game *game)
{
	int		i;
	char	*tmp;

	i = 1;
	if (game->map[1])
	{
		tmp = ft_strtrim(game->map[1], " \t\n");
		while (tmp[i])
		{
			if (tmp[i] != '1' && tmp[i] != ' ')
				return (1);
			i++;
		}
		free(tmp);
		tmp = NULL;
	}
	return (0);
}

int	check_map_valid(t_game *game)
{
	int	i;

	i = 1;
	if (fill_map(game))
		return (1);
	while (game->map[i])
	{
		if (game->map[i][0] == '\n')
			return (1);
		i++;
	}
	if (check_first_index(game->map))
		return (1);
	if (check_first_wall(game))
		return (1);
	if (check_symboles(game->map))
		return (print_error("Error: Undefined character in the map\n", 1), 1);
	if (check_everything(game->map))
		return (1);
	return (0);
}
