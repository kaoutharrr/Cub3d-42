/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:06:42 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:09:42 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	int		len;
	char	*str;

	len = ft_strlen(s);
	str = (char *)(s);
	while (len >= 0)
	{
		if (str[len] == (char)c)
			return (str + len);
		len--;
	}
	if (c == 0)
		return (str + ft_strlen(str));
	return (0);
}

/*int main()
{
	char str[] = "aymayne";
	// printf("%s", ft_strrchr(str,'y'));
	//// printf("%s", strrchr(str,'y'));
	return 0;
}*/