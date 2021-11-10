/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:27:27 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:27:28 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_stack_find(t_stack *st, int n)
{
	while (st)
	{
		if (st->elem == n)
		{
			ft_putstr("povtor arg\n");
			exit(-2);
		}
		st = st->next;
	}
}

t_stack	*ft_stack_init(int ac, char **av, int *flag)
{
	t_stack	*params;
	t_stack	*tmp;
	int		i;
	int		n;

	i = 1;
	params = NULL;
	tmp = NULL;
	if (i < ac && !ft_strcmp(av[i], "-p"))
	{
		*flag = 1;
		i++;
	}
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		ft_stack_find(params, n);
		params = ft_create_elem(n);
		params->next = tmp;
		tmp = params;
		i++;
	}
	ft_stack_reverse(params);
	return (params);
}

char	**ft_init_command(void)
{
	char	**command;

	command = (char **)malloc(sizeof(char *) * 12);
	command[0] = ft_strdup("sa");
	command[1] = ft_strdup("sb");
	command[2] = ft_strdup("ss");
	command[3] = ft_strdup("pa");
	command[4] = ft_strdup("pb");
	command[5] = ft_strdup("ra");
	command[6] = ft_strdup("rb");
	command[7] = ft_strdup("rr");
	command[8] = ft_strdup("rra");
	command[9] = ft_strdup("rrb");
	command[10] = ft_strdup("rrr");
	command[11] = NULL;
	return (command);
}

void	ft_free_all(t_stack **a, t_stack **b, char **command)
{
	int		i;
	t_stack	*tmp;
	t_stack	*del;

	i = 0;
	while (command[i])
		free(command[i++]);
	free(command);
	tmp = *a;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	tmp = *b;
	while (tmp)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}
