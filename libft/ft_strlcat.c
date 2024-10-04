/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkouaz <kkouaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:43:35 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/17 20:57:03 by kkouaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	src_len;
	unsigned int	dst_len;

	src_len = ft_strlen(src);
	i = 0;
	j = 0;
	if ((!dst) && dstsize == 0)
		return (src_len);
	while (dst[j])
		j++;
	dst_len = j;
	if (dstsize == 0 || dstsize <= dst_len)
		return (src_len + dstsize);
	while (src[i] && i < dstsize - dst_len - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (dst_len + src_len);
}

// int main()
// {
// 	char dst[] = "hello";
// 	char src[] = "world";
// 	// printf("%zu\n", ft_strlcat(,src,0));
// 	//// printf("%zu", strlcat(dst,src,4));
// 	return 0;
// }