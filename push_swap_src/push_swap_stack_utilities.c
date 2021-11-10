/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:08:58 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 15:09:00 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_find(t_stack *st, int n)
{
	while (st)
	{
		if (st->elem == n)
		{
			write(1, "povtor arg\n", ft_strlen("povtor arg\n"));
			exit(-2);
		}
		st = st->next;
	}
}

t_stack	*ft_create_elem(int n)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->elem = n;
		new->next = NULL;
		new->f = 1;
	}
	return (new);
}

t_stack	*ft_stack_init(int argc, char **argv)
{
	int		i;
	t_stack	*first;
	t_stack	*tmp;

	i = 1;
	tmp = NULL;
	if (i < argc)
	{
		tmp = ft_create_elem(ft_atoi(argv[i]));
		i++;
	}
	first = tmp;
	while (i < argc)
	{
		ft_stack_find(first, ft_atoi(argv[i]));
		tmp->next = ft_create_elem(ft_atoi(argv[i]));
		tmp = tmp->next;
		i++;
	}
	return (first);
}

int	ft_stack_size(t_stack *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

t_command	*ft_init_command(void)
{
	t_command	*new;

	new = (t_command *)malloc(sizeof(t_command));
	if (new)
	{
		new->answer = ft_strdup("");
		new->f = 0;
	}
	return (new);
}
