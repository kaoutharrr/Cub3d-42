/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 17:20:13 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:07:39 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	int		i;
	char	*new;
	int		j;

	new = (char *)(malloc(sizeof(char) * ft_strlen(s1) + 1));
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	while (s1[j])
	{
		new[i] = s1[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
