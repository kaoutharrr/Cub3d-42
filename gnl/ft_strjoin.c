/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 10:51:19 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 03:03:19 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(char *str)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(char) * ft_strlen2(str) + 1);
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin2(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((ft_strlen2(str) + ft_strlen2(buff)) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (str)
		while (str[++i] != '\0')
			new[i] = str[i];
	while (buff[j] != '\0')
		new[i++] = buff[j++];
	new[i] = '\0';
	free(str);
	return (new);
}
