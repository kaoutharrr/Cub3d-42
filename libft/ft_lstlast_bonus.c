/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 12:44:20 by adihaj            #+#    #+#             */
/*   Updated: 2022/10/31 14:36:02 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//return the position of the last node.

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		else
			lst = lst->next;
	}
	return (lst);
}
