/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:18:15 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 16:18:17 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_long_sort_dop(t_stack **a, t_stack **b,
	t_command **command, int size)
{
	int	n;

	n = ft_size_half(a, command, size, 'a');
	if (n == 2)
		ft_long_sort_dop_two(a, b, command, size);
	if (n > 2)
		ft_long_sort_dop_three(a, b, command, size);
}

int	ft_size_half(t_stack **a, t_command **command, int size, char c)
{
	int	n;

	if ((*a)->f == 1)
	{
		(*command)->f = 1;
		if (c == 'a')
			n = size - size / 2;
		else
			n = size / 2;
	}
	else
	{
		if (c == 'a')
			n = size / 2;
		else
			n = size - size / 2;
	}
	return (n);
}

void	ft_long_sort_dop_two(t_stack **a, t_stack **b,
	t_command **command, int size)
{
	int	size_1;
	int	size_2;

	size_1 = ft_size_half(a, command, size, 'a');
	size_2 = ft_size_half(a, command, size, 'b');
	if (size_1 == 2 && (!(*a) || ft_stack_size(*a) < 2))
		return ;
	if (size_1 == 2 && (!(*b) || ft_stack_size(*b) < 2 || size_2 > 3))
		ft_sort_two(a, command);
	else if (size_1 == 2 && size_2 == 2)
	{
		ft_sort_two(a, command);
		ft_sort_two(b, command);
	}
	else if (size_1 == 2 && size_2 == 3 && ft_stack_size(*b) > 2)
	{
		ft_sort_two(a, command);
		ft_sort_three(b, command);
	}
}

void	ft_long_sort_dop_three(t_stack **a, t_stack **b,
	t_command **command, int size)
{
	int		size_1;
	int		size_2;

	size_1 = ft_size_half(a, command, size, 'a');
	size_2 = ft_size_half(a, command, size, 'b');
	if (size_1 == 3 && (!(*a) || ft_stack_size(*a) < 3))
		return ;
	if (size_1 > 3 && size_2 == 2)
		ft_sort_two(b, command);
	else if (size_1 == 3 && (!(*b) || ft_stack_size(*b) < 2 || size_2 > 3))
		ft_sort_three(a, command);
	else if (size_1 == 3 && size_2 == 2)
	{
		ft_sort_three(a, command);
		ft_sort_two(b, command);
	}
	else if (size_1 == 3 && size_2 == 3 && ft_stack_size(*b) > 2)
	{
		ft_sort_three(a, command);
		ft_sort_three(b, command);
	}
	else if (size_1 > 3 && size_2 == 3)
		ft_sort_three(b, command);
}
