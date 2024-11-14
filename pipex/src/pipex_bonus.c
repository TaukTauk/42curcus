/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:34:38 by talin             #+#    #+#             */
/*   Updated: 2024/11/14 10:29:23 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (ac < 5)
		ft_exit(1);
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		if (ac < 6)
			ft_exit(1);
		i = 3;
		fd_out = ft_open_file(av[ac - 1], 2);
		ft_heredoc(av);
	}
	else
	{
		i = 2;
		fd_in = ft_open_file(av[1], 0);
		fd_out = ft_open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		ft_pipe(av[i++], env);
	dup2(fd_out, 1);
	ft_exec(av[ac - 2], env);
}
