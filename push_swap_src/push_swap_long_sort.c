/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:22:05 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 15:22:07 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_long_sort(t_stack **a, t_stack **b, t_command **command, int size)
{
	int	n;
	int	f[2];

	if (size == 2 || size == 3)
		return ;
	f[0] = size;
	f[1] = (*a)->f == 1;
	n = ft_rotate_push(a, b, command, f);
	if ((*command)->f == 1)
		ft_rotate_back(a, command, n);
	if (size / 2 == 3 || size / 2 == 2)
		ft_long_sort_dop(a, b, command, size);
	if ((*a)->f == 1)
		ft_long_sort(a, b, command, size - size / 2);
	else
		ft_long_sort(a, b, command, size / 2);
	if ((*a)->f == 1)
		ft_long_sort(b, a, command, size / 2);
	else
		ft_long_sort(b, a, command, size - size / 2);
	if ((*a)->f == 1)
		ft_push_back(a, b, command, size / 2);
	else
		ft_push_back(a, b, command, size - size / 2);
}

int	ft_rotate_push(t_stack **a, t_stack **b,
	t_command **command, int *f)
{
	int		n;
	int		mid;
	t_stack	*tmp;
	int		half;

	tmp = *a;
	n = 0;
	mid = ft_mid(*a, f[0]);
	tmp = *a;
	half = f[1] * (f[0] / 2) + (1 - f[1]) * (f[0] - f[0] / 2);
	while (tmp && ((f[1] && half >= 0) || (!f[1] && half > 0)))
	{
		if (((*a)->f == 1 && ((f[1] && tmp->elem < mid) || (!f[1]
						&& tmp->elem > mid))) || ((*a)->f == 2 && ((f[1]
						&& tmp->elem <= mid) || (!f[1] && tmp->elem >= mid))))
		{
			while ((*a)->elem != tmp->elem)
				n = ft_rotate(a, command, n);
			tmp = tmp->next;
			half = ft_push(a, b, command, half);
		}
		else
			tmp = tmp->next;
	}
	return (n);
}

int	ft_rotate(t_stack **a, t_command **command, int n)
{
	ft_command(a, command, "ra\n");
	n++;
	return (n);
}

int	ft_push(t_stack **a, t_stack **b, t_command **command, int half)
{
	if ((*a)->f == 1)
		(*a)->f = 2;
	else
		(*a)->f = 1;
	ft_pa(b, a);
	if ((*a)->f == 1)
		(*command)->answer = ft_add_to_string((*command)->answer, "pb\n", 0);
	else
		(*command)->answer = ft_add_to_string((*command)->answer, "pa\n", 0);
	half--;
	return (half);
}

void	ft_push_back(t_stack **a, t_stack **b, t_command **command, int half)
{
	while (half > 0)
	{
		if ((*b)->f == 1)
			(*b)->f = 2;
		else
			(*b)->f = 1;
		ft_pa(a, b);
		if ((*a)->f == 1)
			(*command)->answer = ft_add_to_string((*command)->answer, "pa\n", 0);
		else
			(*command)->answer = ft_add_to_string((*command)->answer, "pb\n", 0);
		half--;
	}
}
