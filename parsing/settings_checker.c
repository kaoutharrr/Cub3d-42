/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:40:39 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:21:18 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	fill_colors(char **ceiling, char **floor, t_rgb *rgb, t_game *game)
{
	if (check_range(rgb))
		print_error("Error: Rgb range must be [0,255]\n", 1);
	game->colors.c_color.red = ft_atoi(ceiling[0]);
	game->colors.c_color.green = ft_atoi(ceiling[1]);
	game->colors.c_color.blue = ft_atoi(ceiling[2]);
	game->colors.f_color.red = ft_atoi(floor[0]);
	game->colors.f_color.green = ft_atoi(floor[1]);
	game->colors.f_color.blue = ft_atoi(floor[2]);
	game->colors.ceiling_color = rgb_coverter(&game->colors, 1);
	game->colors.floor_color = rgb_coverter(&game->colors, 0);
	return (0);
}

int	turn2int(char *ceiling, char *floor, t_rgb *rgb, t_game *game)
{
	char		**ceiling_range;
	char		**floor_range;
	int			i;

	i = 0;
	ceiling_range = ft_split(ceiling, ',');
	floor_range = ft_split(floor, ',');
	if (!*ceiling_range || !*floor_range || size_of_array(ceiling_range) < 3
		|| size_of_array(floor_range) < 3)
		return (1);
	if (fill_colors(ceiling_range, floor_range, rgb, game))
		return (ft_free(ceiling_range), ft_free(floor_range), 1);
	ft_free(ceiling_range);
	ft_free(floor_range);
	return (0);
}

int	check_ceiling(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' ')
			return (print_error("Error: Wrong rgb format\n", 2), 1);
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	check_rgb(t_rgb *rgb, t_game *game)
{
	int	count_f;
	int	count_c;

	count_c = check_ceiling(rgb->ceiling);
	count_f = check_ceiling(rgb->floor);
	if (count_c > 2 || count_f > 2)
		return (1);
	if (turn2int(rgb->ceiling, rgb->floor, rgb, game))
		return (1);
	return (0);
}

int	check_settings(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (check_rgb(&game->textures.rgb, game))
		print_error("Error: Wrong rgb format\n", 1);
	if (check_map_valid(game))
		print_error("Error: Map not valid\n", 1);
	game->kaouthar_map = (char **)malloc(sizeof (char *)
			*map_lenght_check(game->map) - 2);
	while (i < map_lenght_check(game->map) - 1)
	{
		game->kaouthar_map[j] = game->map[i];
		i++;
		j++;
	}
	game->kaouthar_map[j] = NULL;
	game->map_width = longest_line_raycast(game->kaouthar_map) - 1;
	game->map_height = map_lenght(game->kaouthar_map);
	return (0);
}
