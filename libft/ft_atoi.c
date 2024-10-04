/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:42:49 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:05:15 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* According to the man, "The atoi function converts the initial portion of
 * the string point to by str to int representation."*/

int	ft_atoi(char *str)
{
	int				sign;
	unsigned long	result;
	int				i;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
		|| str[i] == '\f' || str[i] == '\v' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - 48);
	}
	if (result > 9223372036854775807 && sign == 1)
		return (-1);
	else if (result > 9223372036854775807 && sign == -1)
		return (0);
	return (result * sign);
}
