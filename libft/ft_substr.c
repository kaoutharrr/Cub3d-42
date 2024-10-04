/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:03:33 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:10:09 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*new;
	size_t			i;
	size_t			str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start > str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = (str_len - start);
	new = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!new)
		return (NULL);
	while (i < len && s[i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[len] = '\0';
	return (new);
}

// int main()
// {
// 	char product[] = "100-400-0.750-3434.A";
// 	// printf("%s", ft_substr(product,0,4));
// 	system("leaks a.out");
// }