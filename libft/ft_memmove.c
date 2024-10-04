/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 00:27:12 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:03:21 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return ((char *)dst);
	if (dst > src && (src + len > dst))
	{
		while (len--)
		{
			((char *)dst)[len] = ((char *)src)[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

// int main()
// {

// 	// printf("%s\n", ft_memmove("aymen", "aymen", 5));
// 	//// printf("%s\n", memmove("aymen", "aymen", 5));
// }
