/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:08:32 by ubuntu            #+#    #+#             */
/*   Updated: 2024/11/23 20:04:49 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_isspace(char str)
{
	if ((str >= 9 && str <= 13) || str == 32)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_check_input(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (1);
	if (ft_strlen(str) == 1 && !(str[0] >= '0' && str[0] <= '9'))
		return (1);
	while (str[++i])
	{
		if (!(str[i] == '+' || str[i] == '-' \
		|| (str[i] >= '0' && str[i] <= '9') || ft_isspace(str[i])))
			return (1);
		if (str[i + 1] && \
		(str[i] >= '0' && str[i] <= '9') && \
		!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	if (!str || ft_check_input(str))
		ft_exit("Invalid input!");
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		res = res * 10 + (str[i++] - '0');
	if ((res * sign) < 0)
		ft_exit("No negative value!");
	return (res * sign);
}