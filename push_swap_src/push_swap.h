/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:10:32 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 15:10:33 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				elem;
	struct s_stack	*next;
	int				f;
}					t_stack;
typedef struct s_command
{
	char			*answer;
	int				f;
}					t_command;
int			ft_strlen(char const *str);
int			ft_strcmp(char const *s1, char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *src);
int			ft_isdigit(int c);
int			ft_ctoi(const char c);
int			ft_atoi(const char *str);
int			ft_notab(char c);
int			ft_word_count(char *str);
int			ft_word_length(char *str);
char		**ft_split(char *str);
int			ft_stack_size(t_stack *begin_list);
void		ft_stack_find(t_stack *st, int n);
t_stack		*ft_stack_init(int ac, char **av);
t_stack		*ft_create_elem(int n);
t_command	*ft_init_command(void);
void		ft_free_all(t_stack **a, t_stack **b, t_command **command);
void		ft_short_sort(t_stack **a, t_stack **b,
				t_command	**command, int size);
void		ft_short_sort_dop(t_stack **a, t_command	**command);
void		ft_long_sort(t_stack **a, t_stack **b,
				t_command **command, int size);
int			ft_rotate_push(t_stack **a, t_stack **b,
				t_command **command, int *f);
int			ft_rotate(t_stack **a, t_command **command, int n);
int			ft_push(t_stack **a, t_stack **b, t_command **command, int half);
void		ft_push_back(t_stack **a, t_stack **b,
				t_command **command, int half);
void		ft_rotate_back(t_stack **a, t_command **command, int back);
void		ft_sort_two(t_stack **a, t_command **command);
void		ft_sort_three(t_stack **a, t_command **command);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_sa(t_stack **a);
void		ft_ra(t_stack **a);
void		ft_rra(t_stack **a);
void		ft_command(t_stack **stack, t_command **command, char *str);
void		ft_long_sort_dop(t_stack **a, t_stack **b,
				t_command **command, int size);
int			ft_size_half(t_stack **a, t_command **command, int size, char c);
void		ft_long_sort_dop_two(t_stack **a, t_stack **b,
				t_command **command, int size);
void		ft_long_sort_dop_three(t_stack **a, t_stack **b,
				t_command **command, int size);
void		ft_swap(int *a, int *b);
int			ft_half_array(int *array, int begin, int end);
void		ft_quick_sort(int *stack1, int start, int end);
int			*ft_array_from_stack(t_stack *a, int size);
int			ft_mid(t_stack *a, int len);
void		ft_print_answer(char *answer);
char		*ft_add_to_string(char *to, char *add, int flag);
int			ft_add_command(char **answer, char **res, char *c1, char *c2);
int			ft_add_others(char **tmp, char **res);
void		ft_free_array(char	**tmp);

#endif
