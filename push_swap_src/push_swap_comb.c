/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:08:50 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 16:08:52 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_command_dop(t_stack **stack, char **com)
{
	int	i;

	i = 0;
	while (com[i])
	{
		if (!ft_strcmp(com[i], "sa"))
			ft_sa(stack);
		else if (!ft_strcmp(com[i], "ra"))
			ft_ra(stack);
		else if (!ft_strcmp(com[i], "rra"))
			ft_rra(stack);
		i++;
	}
}

void	ft_command(t_stack **stack, t_command **command, char *str)
{
	int		i;
	char	**com;
	char	*str2;

	str2 = ft_strdup(str);
	com = ft_split(str);
	ft_command_dop(stack, com);
	ft_free_array(com);
	i = 0;
	if ((*stack)->f == 2)
	{
		while (str2[i])
		{
			if (str2[i] == 'a')
				str2[i] = 'b';
			i++;
		}
	}
	(*command)->answer = ft_add_to_string((*command)->answer, str2, 0);
	free(str2);
}
