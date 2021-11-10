/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:29:36 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:29:38 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_run(t_stack **a, t_stack **b, char **command, char *line)
{
	int	i;

	i = 0;
	while (command[i])
	{
		if (ft_strcmp(command[i], line) == 0)
		{
			ft_action(line, a, b);
			break ;
		}
		i++;
	}
	if (i == 11)
		ft_putstr("command not found\n");
}

void	ft_is_other_action(char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "rr"))
	{
		ft_stack_rotate(*a);
		ft_stack_rotate(*b);
	}
	else if (!ft_strcmp(line, "ss"))
	{
		ft_stack_swap(*a);
		ft_stack_swap(*b);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_stack_reverse_rotate(*a);
		ft_stack_reverse_rotate(*b);
	}
}

void	ft_action(char *line, 	t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		ft_stack_swap(*a);
	else if (!ft_strcmp(line, "sb"))
		ft_stack_swap(*b);
	else if (!ft_strcmp(line, "pa"))
		ft_stack_push(b, a);
	else if (!ft_strcmp(line, "pb"))
		ft_stack_push(a, b);
	else if (!ft_strcmp(line, "ra"))
		ft_stack_rotate(*a);
	else if (!ft_strcmp(line, "rb"))
		ft_stack_rotate(*b);
	else if (!ft_strcmp(line, "rra"))
		ft_stack_reverse_rotate(*a);
	else if (!ft_strcmp(line, "rrb"))
		ft_stack_reverse_rotate(*b);
	else
		ft_is_other_action(line, a, b);
}
