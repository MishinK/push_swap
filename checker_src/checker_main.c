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

#include "checker.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**command;
	char	*line;
	int		flag;

	command = ft_init_command();
	flag = 0;
	a = ft_stack_init(ac, av, &flag);
	b = NULL;
	if (flag)
		ft_stack_print(a, b);
	while (get_next_line(0, &line) > 0)
	{
		ft_run(&a, &b, command, line);
		if (flag)
			ft_stack_print(a, b);
		free(line);
	}
	ft_stack_issort(a, ac - 1 - (flag == 1));
	free(line);
	ft_free_all(&a, &b, command);
	return (0);
}
