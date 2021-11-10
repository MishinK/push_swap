/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ptint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:26:02 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:26:03 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_stack_print_dop(t_stack **a, t_stack **b, int *high)
{
	if (*a && high[0] <= high[1])
	{
		ft_putnbr((*a)->elem);
		if (high[1] >= high[2])
			ft_putstr("    ");
		*a = (*a)->next;
	}
	if (*b && high[0] <= high[2])
	{
		if (high[2] > high[1])
			ft_putstr("    ");
		if (high[0] > high[1])
			ft_putstr(" ");
		ft_putnbr((*b)->elem);
		*b = (*b)->next;
	}
	ft_putstr("\n");
}

void	ft_stack_print(t_stack *a, t_stack *b)
{
	int	high[3];

	ft_putstr("-------------\na    b\n-    -\n");
	high[1] = ft_stack_size(a);
	high[2] = ft_stack_size(b);
	if (high[1] > high[2])
		high[0] = high[1];
	else
		high[0] = high[2];
	while (high[0])
	{
		ft_stack_print_dop(&a, &b, high);
		high[0]--;
	}
	ft_putstr("-------------\n");
}

void	ft_stack_issort(t_stack *st, int size)
{
	if (ft_stack_size(st) != size)
	{
		ft_putstr("КО\n");
		return ;
	}
	if (st)
	{
		while (st->next)
		{
			if (st->elem > st->next->elem)
			{
				ft_putstr("КО\n");
				return ;
			}
			st = st->next;
		}
	}
	ft_putstr("OK\n");
}
