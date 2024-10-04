/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:03:44 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:08:18 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// static char ft_mp(unsigned int m, char c)
// {
// 	c += 32;
// 	return (c);
// }
// static char ft_sum(unsigned int m, char c)
// {
// 	c -= 32;
// 	return (c);
// }
// int main()
// {
// 	// printf("%s\n", ft_strmapi("ABCDEF", ft_mp));
// 	// printf("%s", ft_strmapi("abcdef", ft_sum));
// }