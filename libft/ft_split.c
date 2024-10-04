/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adihaj <adihaj@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:23:00 by adihaj            #+#    #+#             */
/*   Updated: 2023/08/19 04:06:43 by adihaj           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static int	word_size(char *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **strs, int j)
{
	while (j >= 0)
	{
		free(strs[j]);
		j--;
	}
	free(strs);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**strs;
	int		j;

	i = 0;
	j = 0;
	strs = (char **)malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (j < word_counter(s, c))
	{
		while (s[i] == c)
			i++;
		strs[j] = ft_substr(s, i, word_size(s, c, i));
		if (!strs[j])
		{
			ft_free(strs, j);
			return (NULL);
		}
		i += word_size(s, c, i);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
