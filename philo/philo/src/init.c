/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:43:36 by talin             #+#    #+#             */
/*   Updated: 2024/11/26 14:03:55 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_assign_forks(int i, t_philo *philo)
{
	if (philo->id % 2)
	{
		philo->left_fork = &philo->data->fork[i];
		philo->right_fork = &philo->data->fork[(i + 1) \
		% philo->data->num_philo];
	}
	else
	{
		philo->right_fork = &philo->data->fork[i];
		philo->left_fork = &philo->data->fork[(i + 1) \
		% philo->data->num_philo];
	}
}

int	ft_init_philo(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philo);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->philos || !data->fork)
		return (1);
	memset(data->philos, 0, data->num_philo * sizeof(t_philo));
	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (1);
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].t_ate = 0;
		ft_assign_forks(i, &data->philos[i]);
	}
	return (0);
}

int	ft_init_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->mutex_dead, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mutex_meal_count, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mutex_log, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&data->mutex_last_meal, NULL) != 0)
		return (1);
	return (0);
}

int	ft_init_data(char **av, int ac, t_data *data)
{
	int	status;

	status = 0;
	data->dead = 0;
	data->num_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		data->num_eat = ft_atoi(av[5]);
		if (data->num_eat == 0)
			status = 1;
	}
	else
		data->num_eat = 0;
	if (ft_init_philo(data))
		status = 1;
	if (ft_init_mutex(data))
		status = 1;
	return (status);
}
