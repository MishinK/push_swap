/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:31:48 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:31:54 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
}					t_stack;
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ctoi(const char c);
int					ft_atoi(const char *str);
char				*ft_strdup(const char *src);
void				ft_swap(int *a, int *b);
t_stack				*ft_create_elem(int data);
int					ft_stack_size(t_stack *begin_list);
t_stack				*ft_stack_last(t_stack *begin_list);
void				ft_stack_print_dop(t_stack **a, t_stack **b, int *high);
void				ft_stack_print(t_stack *a, t_stack *b);
void				ft_stack_issort(t_stack *st, int size);
void				ft_stack_find(t_stack *st, int n);
t_stack				*ft_stack_init(int ac, char **av, int *flag);
char				**ft_init_command(void);
void				ft_free_all(t_stack **a, t_stack **b, char **command);
void				ft_run(t_stack **a, t_stack **b,
						char **command, char *line);
void				ft_is_other_action(char *line, t_stack **a, t_stack **b);
void				ft_action(char *line, 	t_stack **a, t_stack **b);
void				ft_stack_swap(t_stack *st);
void				ft_stack_rotate(t_stack *st);
void				ft_stack_reverse(t_stack *st);
void				ft_stack_reverse_rotate(t_stack *st);
void				ft_stack_push(t_stack **a, t_stack **b);
int					ft_stack_size(t_stack *begin_list);
void				ft_putstr(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);

#endif