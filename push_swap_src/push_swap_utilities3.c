/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 02:25:22 by ashea             #+#    #+#             */
/*   Updated: 2021/06/09 02:25:24 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_notab(char c)
{
	return (c != '\t' && c != '\v' && c != '\n' && c != ' ');
}

int	ft_word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (ft_notab(str[i]))
			count++;
		while (str[i + 1] && ft_notab(str[i]))
			i++;
		i++;
	}
	return (count);
}

int	ft_word_length(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (!ft_notab(str[i]))
		i++;
	while (str[i] && ft_notab(str[i]))
	{
		length++;
		i++;
	}
	return (length);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**word;

	i = 0;
	k = 0;
	word = (char **)malloc(sizeof(char *) * (ft_word_count(str) + 1));
	while (i < ft_word_count(str))
	{
		word[i] = (char *)malloc(sizeof(char) * (ft_word_length(&str[k]) + 1));
		j = 0;
		while (!ft_notab(str[k]))
			k++;
		while (str[k] && ft_notab(str[k]))
		{
			word[i][j] = str[k];
			j++;
			k++;
		}
		word[i][j] = '\0';
		i++;
	}
	word[i] = NULL;
	return (word);
}
