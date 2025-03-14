/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:50:53 by talin             #+#    #+#             */
/*   Updated: 2024/11/26 14:13:51 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	monitor_msg(philo, TAKE_FORK);
	pthread_mutex_lock(philo->right_fork);
	monitor_msg(philo, TAKE_FORK);
	if (ft_check_end(philo->data))
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	monitor_msg(philo, EAT);
	pthread_mutex_lock(&philo->data->mutex_last_meal);
	philo->last_dine = ft_get_current_time();
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
	ft_wait(philo->data, philo->data->t_eat);
	if (!ft_check_end(philo->data))
	{
		pthread_mutex_lock(&philo->data->mutex_meal_count);
		philo->t_ate++;
		pthread_mutex_unlock(&philo->data->mutex_meal_count);
	}
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_sleep(t_philo *philo)
{
	if (ft_check_end(philo->data))
		return ;
	monitor_msg(philo, SLEEP);
	ft_wait(philo->data, philo->data->t_sleep);
}

void	ft_think(t_philo *philo)
{
	time_t	t_think;
	time_t	x;

	if (ft_check_end(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->mutex_last_meal);
	t_think = philo->data->t_die;
	x = (ft_get_current_time() - philo->last_dine) + philo->data->t_eat;
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
	if (x >= t_think)
		t_think = 0;
	else
	{
		if (t_think > 500)
			t_think = 150;
	}
	monitor_msg(philo, THINK);
	ft_wait(philo->data, t_think);
	return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->mutex_last_meal);
	philo->last_dine = philo->data->t_start;
	pthread_mutex_unlock(&philo->data->mutex_last_meal);
	while (ft_get_current_time() < philo->data->t_start)
		continue ;
	if (philo->data->num_philo == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		monitor_msg(philo, TAKE_FORK);
		pthread_mutex_unlock(philo->left_fork);
		ft_wait(philo->data, philo->data->t_die);
		return (NULL);
	}
	if (philo->id % 2)
		ft_wait(philo->data, philo->data->t_eat / 2);
	while (!ft_check_end(philo->data))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (NULL);
}
