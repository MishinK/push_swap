/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:12:23 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 16:12:24 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_array(char	**tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free (tmp);
}

void	ft_print_answer(char *answer)
{
	char	**tmp;
	char	*res;
	int		i;

	i = 0;
	res = ft_strdup("");
	tmp = ft_split(answer);
	while (tmp[i])
	{
		if (tmp[i] && (!ft_strcmp(tmp[i], "pa") || !ft_strcmp(tmp[i], "pb")))
			i += ft_add_command(&tmp[i], &res, "pa", "pb");
		if (tmp[i] && (!ft_strcmp(tmp[i], "ra") || !ft_strcmp(tmp[i], "rra")))
			i += ft_add_command(&tmp[i], &res, "ra", "rra");
		if (tmp[i] && (!ft_strcmp(tmp[i], "rb") || !ft_strcmp(tmp[i], "rrb")))
			i += ft_add_command(&tmp[i], &res, "rb", "rrb");
		if (tmp[i] && !(!ft_strcmp(tmp[i], "pa") || !ft_strcmp(tmp[i], "pb")
				|| !ft_strcmp(tmp[i], "ra") || !ft_strcmp(tmp[i], "rb")
				|| !ft_strcmp(tmp[i], "rra") || !ft_strcmp(tmp[i], "rrb")))
			i += ft_add_others(&tmp[i], &res);
	}
	write(1, res, ft_strlen(res));
	free(res);
	ft_free_array(tmp);
}

char	*ft_add_to_string(char *to, char *add, int flag)
{
	char	*del;

	del = to;
	to = ft_strjoin(to, add);
	free(del);
	if (flag)
	{
		del = to;
		to = ft_strjoin(to, "\n");
		free(del);
	}
	return (to);
}

int	ft_add_command(char **answer, char **res, char *c1, char *c2)
{
	int		k[2];
	int		diff;
	int		i;

	k[0] = 0;
	k[1] = 0;
	diff = 0;
	i = 0;
	while (answer[i] && (!ft_strcmp(answer[i], c1)
			|| !ft_strcmp(answer[i], c2)))
	{
		if (!ft_strcmp(answer[i], c1))
			k[0]++;
		if (!ft_strcmp(answer[i], c2))
			k[1]++;
		i++;
	}
	diff = (k[0] > k[1]) * (k[0] - k[1]);
	while (diff-- > 0)
		*res = ft_add_to_string(*res, c1, 1);
	diff = (k[0] < k[1]) * (k[1] - k[0]);
	while (diff-- > 0)
		*res = ft_add_to_string(*res, c2, 1);
	return (i);
}

int	ft_add_others(char **tmp, char **res)
{
	int	i;

	i = 0;
	while (tmp[i] && !(!ft_strcmp(tmp[i], "pa") || !ft_strcmp(tmp[i], "pb")
			|| !ft_strcmp(tmp[i], "ra") || !ft_strcmp(tmp[i], "rb")
			|| !ft_strcmp(tmp[i], "rra") || !ft_strcmp(tmp[i], "rrb")))
	{
		*res = ft_add_to_string(*res, tmp[i], 1);
		i++;
	}
	return (i);
}
