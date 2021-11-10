/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 02:16:13 by ashea             #+#    #+#             */
/*   Updated: 2021/06/09 02:16:14 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_sort_three_dop1(t_stack **a, t_command **command, int f)
{
	if (f * (*a)->elem < f * (*a)->next->elem
		&& f * (*a)->next->elem < f * (*a)->next->next->elem)
		return (1);
	else if (f * (*a)->elem > f * (*a)->next->elem
		&& f * (*a)->next->elem < f * (*a)->next->next->elem
		&& f * (*a)->elem < f * (*a)->next->next->elem)
	{
		if (ft_stack_size(*a) > 3)
			ft_command(a, command, "sa\n");
		else
			ft_sort_two(a, command);
		return (1);
	}
	return (0);
}

static int	ft_sort_three_dop2(t_stack **a, t_command **command, int f)
{
	if (f * (*a)->elem < f * (*a)->next->elem
		&& f * (*a)->next->elem > f * (*a)->next->next->elem
		&& f * (*a)->elem < f * (*a)->next->next->elem)
	{
		if (ft_stack_size(*a) > 3)
			ft_command(a, command, "ra\nsa\nrra\n");
		else
			ft_command(a, command, "rra\nsa\n");
		return (1);
	}
	else if (f * (*a)->elem > f * (*a)->next->elem
		&& f * (*a)->elem > f * (*a)->next->next->elem
		&& f * (*a)->next->elem < f * (*a)->next->next->elem)
	{
		if (ft_stack_size(*a) > 3)
			ft_command(a, command, "sa\nra\nsa\nrra\n");
		else
			ft_command(a, command, "ra\n");
		return (1);
	}
	return (0);
}

static int	ft_sort_three_dop3(t_stack **a, t_command **command, int f)
{
	if (f * (*a)->elem < f * (*a)->next->elem
		&& f * (*a)->elem > f * (*a)->next->next->elem
		&& f * (*a)->next->elem > f * (*a)->next->next->elem)
	{
		if (ft_stack_size(*a) > 3)
			ft_command(a, command, "ra\nsa\nrra\nsa\n");
		else
			ft_command(a, command, "rra\n");
		return (1);
	}
	else if (f * (*a)->elem > f * (*a)->next->elem
		&& f * (*a)->next->elem > f * (*a)->next->next->elem)
	{
		if (ft_stack_size(*a) > 3)
			ft_command(a, command, "sa\nra\nsa\nrra\nsa\n");
		else
			ft_command(a, command, "ra\nsa\n");
		return (1);
	}
	return (0);
}

void	ft_sort_three(t_stack **a, t_command **command)
{
	int	f;

	if ((*a)->f == 1)
		f = 1;
	else
		f = -1;
	if (ft_sort_three_dop1(a, command, f))
		return ;
	if (ft_sort_three_dop2(a, command, f))
		return ;
	if (ft_sort_three_dop3(a, command, f))
		return ;
}
