/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashea <ashea@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:22:12 by ashea             #+#    #+#             */
/*   Updated: 2021/06/08 12:22:13 by ashea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ctoi(const char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	return (0);
}

void	ft_atoi_dop(const char *str)
{
	if (!ft_isdigit(str[0]))
	{
		ft_putstr("wrong argument\n");
		exit(-1);
	}
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (*str)
	{
		ft_atoi_dop(str);
		if (res == 0)
			res = sign * ctoi(*str);
		else
			res = res * 10 + sign * ctoi(*str);
		if (res % 10 != sign * ctoi(*str) % 10 && sign < 0)
			return (0);
		if (res % 10 != sign * ctoi(*str) % 10 && sign >= 0)
			return (-1);
		str++;
	}
	return (res);
}
