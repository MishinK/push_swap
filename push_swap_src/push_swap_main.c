/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 01:16:28 by ashea             #+#    #+#             */
/*   Updated: 2021/03/31 01:16:30 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_command	*command;
	int			size;

	a = ft_stack_init(ac, av);
	b = NULL;
	command = ft_init_command();
	size = ft_stack_size(a);
	if (size < 4)
		ft_short_sort(&a, &b, &command, size);
	else
		ft_long_sort(&a, &b, &command, size);
	ft_print_answer(command->answer);
	ft_free_all(&a, &b, &command);
	return (0);
}
