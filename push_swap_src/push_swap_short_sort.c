/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:19:10 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 15:19:11 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_short_sort(t_stack **a, t_stack **b,
		t_command	**command, int len_a)
{
	(void)b;
	if (len_a == 2 && !((*a)->elem < (*a)->next->elem))
		(*command)->answer = ft_add_to_string((*command)->answer, "sa\n", 0);
	if (len_a == 3 && !((*a)->elem < (*a)->next->elem
			&& (*a)->next->elem < (*a)->next->next->elem))
		ft_short_sort_dop(a, command);
	return ;
}

void	ft_short_sort_dop(t_stack **a, t_command	**command)
{
	if ((*a)->elem > (*a)->next->elem
		&& (*a)->next->elem < (*a)->next->next->elem
		&& (*a)->elem < (*a)->next->next->elem)
		(*command)->answer = ft_add_to_string((*command)->answer, "sa\n", 0);
	else if ((*a)->elem < (*a)->next->elem
		&& (*a)->next->elem > (*a)->next->next->elem
		&& (*a)->elem < (*a)->next->next->elem)
		(*command)->answer = ft_add_to_string((*command)->answer, "rra\nsa\n", 0);
	else if ((*a)->elem > (*a)->next->elem
		&& (*a)->elem > (*a)->next->next->elem
		&& (*a)->next->elem < (*a)->next->next->elem)
		(*command)->answer = ft_add_to_string((*command)->answer, "ra\n", 0);
	else if ((*a)->elem < (*a)->next->elem
		&& (*a)->elem > (*a)->next->next->elem
		&& (*a)->next->elem > (*a)->next->next->elem)
		(*command)->answer = ft_add_to_string((*command)->answer, "rra\n", 0);
	else if ((*a)->elem > (*a)->next->elem
		&& (*a)->next->elem > (*a)->next->next->elem)
		(*command)->answer = ft_add_to_string((*command)->answer, "ra\nsa\n", 0);
}
