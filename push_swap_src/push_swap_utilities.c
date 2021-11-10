/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:51:40 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 14:51:42 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	int				i;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	i = 0;
	while (s1_copy[i] == s2_copy[i] && s1_copy[i])
		i++;
	if (s1_copy[i] != s2_copy[i])
		return (s1_copy[i] - s2_copy[i]);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	if (!(s1) || !(s2))
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*src2;

	i = 0;
	while (src[i] != '\0')
		i++;
	src2 = (char *)malloc((i + 1) * sizeof(char));
	if (!src2)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

void	ft_free_all(t_stack **a, t_stack **b, t_command **command)
{
	t_stack	*tmp;
	t_stack	*del;

	if (*command)
	{
		free((*command)->answer);
		free(*command);
	}
	tmp = *a;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*a = NULL;
	tmp = *b;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	*b = NULL;
}
