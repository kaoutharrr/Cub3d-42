/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 13:38:24 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/17 20:57:03 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
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
// 	// printf("%s\n", ft_striteri("ABCDEF", ft_mp));
// 	// printf("%s", ft_striteri("abcdef", ft_sum));
// }