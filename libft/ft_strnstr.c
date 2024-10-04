/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:18:03 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:09:34 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	char	*srch;
	char	*to_find;

	srch = (char *)(haystack);
	to_find = (char *)(needle);
	i = 0;
	if ((srch == NULL || to_find == NULL) && n == 0)
		return (NULL);
	if (to_find[0] == '\0')
		return (srch);
	while (srch[i] && i < n)
	{
		j = 0;
		while (srch[i + j] && (srch[i + j] == to_find[j]) && (i + j) < n)
		{
			j++;
			if (to_find[j] == '\0')
				return (&srch[i]);
		}
		i++;
	}
	return (NULL);
}

// #include<stdio.h>
// int main()
// {
//     char *a = "jhlevijb";
//     char *b = "levi";
//     // printf("%s", ft_strnstr(a,b,6));
// }
