/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:58:17 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:16:46 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	check_map_name(char *map_name)
{
	int	i;

	i = 0;
	if (map_name != NULL)
	{
		if (!ft_strchr(map_name, '.'))
			return (1);
		if (map_name[ft_strlen(map_name) - 4] != '.'
			|| map_name[ft_strlen(map_name) - 3] != 'c'
			|| map_name[ft_strlen(map_name) - 2] != 'u'
			|| map_name[ft_strlen(map_name) - 1] != 'b'
			|| map_name[ft_strlen(map_name) - 5] == 47)
			return (1);
		if (access(map_name, F_OK | R_OK) == -1)
			return (1);
	}
	return (0);
}

int	open_file(char *path, t_game *game)
{
	int	fd;

	fd = open(path, O_RDWR);
	if (fd < 0)
		print_error("Error: can't open the file\n", 1);
	game->file_len = ft_count_lines(path);
	return (fd);
}

void	get_map_init(char *all, int lines, int fd, t_game *game)
{
	if (all[0] == '\0')
		print_error("Error: invalid map\n", 1);
	game->join[lines] = NULL;
	close(fd);
	game->file = ft_split(all, '\n');
	free(all);
}

int	get_map(char *file_path, t_game *game)
{
	int		fd;
	char	*all;
	char	*line;
	int		lines;

	lines = 0;
	all = ft_strdup("");
	line = "";
	fd = open_file(file_path, game);
	game->join = (char **)malloc(sizeof(char *) * (game->file_len + 1));
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->join[lines] = ft_strdup(line);
		lines++;
		all = ft_strjoin(all, line);
		free(line);
	}
	get_map_init(all, lines, fd, game);
	return (0);
}
