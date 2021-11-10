/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 16:15:28 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 16:15:30 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_back(t_stack **a, t_command **command, int back)
{
	if (ft_stack_size(*a) == 2)
	{
		ft_sort_two(a, command);
		return ;
	}
	if (ft_stack_size(*a) == 3)
	{
		ft_sort_three(a, command);
		return ;
	}
	while (back)
	{
		ft_command(a, command, "rra\n");
		back--;
	}
}

void	ft_sort_two(t_stack **a, t_command **command)
{
	if ((*a)->f == 1 && ((*a)->elem > (*a)->next->elem))
	{
		ft_sa(a);
		(*command)->answer = ft_add_to_string((*command)->answer, "sa\n", 0);
	}
	else if ((*a)->f == 2 && ((*a)->elem < (*a)->next->elem))
	{
		ft_sa(a);
		(*command)->answer = ft_add_to_string((*command)->answer, "sb\n", 0);
	}
}
