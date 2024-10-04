/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:55:33 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:06:11 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//According to the man this function copies bytes from string src to string dst.

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	s = (unsigned char *)(src);
	d = (unsigned char *)(dst);
	if (!dst && !src)
		return (NULL);
	if (dst == src)
		return (dst);
	while (0 < len)
	{
		*d = *s;
		d++;
		s++;
		len--;
	}
	return (dst);
}

/*int main()
{
	char dst[10];
	char src[] = "levi";
	ft_memcpy(dst, src, sizeof(char) * 2);
	//memcpy(dst,src,sizeof(char) * 2);
	// printf("%s\n", dst);
	
}*/

// int main()
// {
// 	// printf("%s", ft_memcpy("aymen", "aymen", 5));
// }