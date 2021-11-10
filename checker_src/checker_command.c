/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:30:51 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:30:53 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_stack_swap(t_stack *st)
{
	if (ft_stack_size(st) > 1)
		ft_swap(&st->elem, &st->next->elem);
}

void	ft_stack_rotate(t_stack *st)
{
	if (ft_stack_size(st) < 2)
		return ;
	while (st->next)
	{
		ft_swap(&st->elem, &st->next->elem);
		st = st->next;
	}
}

void	ft_stack_reverse(t_stack *st)
{
	t_stack	*list;
	int		i;
	int		j;
	int		number;

	number = ft_stack_size(st);
	if (number < 2)
		return ;
	i = 0;
	while (i < number)
	{
		j = i;
		list = st;
		while (j < number - 1)
		{
			ft_swap(&list->elem, &list->next->elem);
			list = list->next;
			j++;
		}
		i++;
	}
}

void	ft_stack_reverse_rotate(t_stack *st)
{
	ft_stack_reverse(st);
	ft_stack_rotate(st);
	ft_stack_reverse(st);
}

void	ft_stack_push(t_stack **a, t_stack **b)
{
	t_stack	*c;

	if (*a)
	{
		c = ft_create_elem((*a)->elem);
		c->next = *b;
		*b = c;
		c = *a;
		*a = (*a)->next;
		free(c);
	}
}
