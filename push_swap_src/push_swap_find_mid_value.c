/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 15:06:06 by ashea             #+#    #+#             */
/*   Updated: 2021/06/01 15:06:07 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_half_array(int *array, int begin, int end)
{
	int	val_end;
	int	k;
	int	i;

	val_end = array[end];
	k = begin - 1;
	i = begin;
	while (i <= end - 1)
	{
		if (array[i] <= val_end)
		{
			k++;
			ft_swap(&array[k], &array[i]);
		}
		i++;
	}
	ft_swap(&array[k + 1], &array[end]);
	return (k + 1);
}

void	ft_quick_sort(int *array, int begin, int end)
{
	int	*array2;
	int	i;
	int	k;

	i = -1;
	array2 = (int *)malloc(sizeof(int) * (end + 1));
	array2[++i] = begin;
	array2[++i] = end;
	while (i >= 0)
	{
		end = array2[i--];
		begin = array2[i--];
		k = ft_half_array(array, begin, end);
		if (k - 1 > begin)
		{
			array2[++i] = begin;
			array2[++i] = k - 1;
		}
		if (k + 1 < end)
		{
			array2[++i] = k + 1;
			array2[++i] = end;
		}
	}
	free(array2);
}

int	ft_mid(t_stack *a, int size)
{
	int	*array;
	int	mid;

	if (ft_stack_size(a) < size)
		size = ft_stack_size(a);
	array = ft_array_from_stack(a, size);
	ft_quick_sort(array, 0, size - 1);
	mid = array[size / 2];
	free(array);
	return (mid);
}

int	*ft_array_from_stack(t_stack *a, int size)
{
	int	*array;
	int	i;

	array = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		array[i] = a->elem;
		a = a->next;
		i++;
	}
	return (array);
}
