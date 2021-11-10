/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:24:04 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:24:05 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

t_stack	*ft_create_elem(int data)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (elem)
	{
		elem->elem = data;
		elem->next = NULL;
	}
	return (elem);
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

t_stack	*ft_stack_last(t_stack *begin_list)
{
	t_stack	*tmp;

	if (!begin_list)
		return (NULL);
	tmp = begin_list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
