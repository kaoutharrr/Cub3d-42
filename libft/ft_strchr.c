/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:12:10 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:06:56 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr(char *s, int c)
{
	int		i;
	char	m;

	i = 0;
	m = (char)c;
	while (s[i])
	{
		if (s[i] == m)
			return (1);
		i++;
	}
	if (!m && s[i] == '\0')
		return (1);
	return (0);
}

/*int main()
{
	char str[] = "aymane";
	// printf("%s", ft_strchr(str,'y'));
	return 0;
}*/