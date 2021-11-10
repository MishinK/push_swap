/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:10:25 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 16:10:27 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*s1;
	t_stack	*s2;

	s1 = *a;
	s2 = *b;
	if (!s2)
		return ;
	tmp = s2;
	s2 = s2->next;
	*b = s2;
	if (!s1)
	{
		s1 = tmp;
		s1->next = NULL;
		*a = s1;
	}
	else
	{
		tmp->next = s1;
		*a = tmp;
	}
}

void	ft_sa(t_stack **a)
{
	t_stack	*s;

	s = *a;
	if (s && s->next)
		ft_swap(&s->elem, &s->next->elem);
}

void	ft_ra(t_stack **a)
{
	t_stack	*begin;
	t_stack	*end;
	t_stack	*s;

	s = *a;
	if (!(s && s->next))
		return ;
	begin = s;
	s = s->next;
	end = s;
	while (end->next)
		end = end->next;
	end->next = begin;
	begin->next = NULL;
	*a = s;
}

void	ft_rra(t_stack **a)
{
	t_stack	*end;
	t_stack	*early;
	t_stack	*s;

	s = *a;
	if (!(s && s->next))
		return ;
	end = s;
	while (end->next)
	{
		early = end;
		end = end->next;
	}
	end->next = s;
	early->next = NULL;
	*a = end;
}
