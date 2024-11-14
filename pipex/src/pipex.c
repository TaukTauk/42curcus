/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:18:11 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 21:08:02 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	t_file	new;

	if (ac != 5)
		ft_exit(1);
	new.in_fd = ft_open_file(av[1], 0);
	new.out_fd = ft_open_file(av[ac - 1], 1);
	new.num = 2;
	new.size = ac -3;
	ft_pipe(av, env, new);
}
