/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:53:49 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/17 20:57:03 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	new = malloc(sizeof(char) * ((ft_strlen(str) + ft_strlen(buff)) + 1));
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
// int main()
// {
//       char t1[] = "levi";
//       char t2[] = "ackerman";
//       // printf("%s\n", ft_strjoin(t1,t2));
// }