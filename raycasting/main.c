/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:52:29 by kkouaz            #+#    #+#             */
/*   Updated: 2023/08/19 04:38:00 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int ac, char **av)
{
	t_game	game;
	char	*file_path;

	if (ac == 2)
	{
		file_path = av[1];
		if (check_map_name(file_path))
			return (ft_putstr_fd("Error\n", 2), 1);
		if (get_map(file_path, &game))
			return (ft_putstr_fd("Error: cannot read the map\n", 2), 1);
		if (parse_settings(&game))
			return (ft_free(game.join), ft_free(game.file)
				, ft_putstr_fd("Error: Bad parameters\n", 2)
				, free_textures(&game), 1);
		if (check_settings(&game))
			return (ft_putstr_fd("Error: Wrong path\n", 2), 1);
		start_game(game);
		ft_free(game.join);
		ft_free(game.file);
		ft_free(game.map);
		free_textures(&game);
	}
	else
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	return (0);
}
