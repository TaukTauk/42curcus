/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:01:49 by talin             #+#    #+#             */
/*   Updated: 2024/11/05 15:17:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int ac, char **av, char **envp)
{
	if (ac < 5)
		return (ft_printf("./pipex infile cmd cmd1 outfile\n"));
	if ((ft_strncmp(av[1], "here_doc", 9) != 0))
	{
		if (!ft_pipex(ac, av, envp))
		{
			ft_write_output_one(av, ac);
			ft_printf("Error\n");
			return (1);
		}
	}
	else
	{
		if (ac < 6)
			return (ft_printf("./pipex here_doc LIMITER cmd cmd1 outfile\n"));
		if (!ft_heredoc(ac, av, envp))
		{
			ft_write_output_two(av, ac);
			ft_printf("Error\n");
			return (1);
		}
	}
	return (0);
}
