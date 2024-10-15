/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:44:39 by talin             #+#    #+#             */
/*   Updated: 2024/10/15 14:16:14 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move_up(t_mapping *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			if (game->game_map[y][x] == 'P')
			{
				if (game->game_map[y - 1][x] == '0' \
				|| game->game_map[y - 1][x] == 'C' \
				|| game->game_map[y - 1][x] == 'E')
				{
					if (ft_check_count(game, game->game_map[y - 1][x]))
						return ;
					game->game_map[y - 1][x] = 'P';
					game->game_map[y][x] = '0';
					ft_printf("Move up\n");
					return ;
				}
			}
		}
	}
}

void	ft_move_down(t_mapping *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			if (game->game_map[y][x] == 'P')
			{
				if (game->game_map[y + 1][x] == '0' \
				|| game->game_map[y + 1][x] == 'C' \
				|| game->game_map[y + 1][x] == 'E')
				{
					if (ft_check_count(game, game->game_map[y - 1][x]))
						return ;
					game->game_map[y + 1][x] = 'P';
					game->game_map[y][x] = '0';
					ft_printf("Move up\n");
					return ;
				}
			}
		}
	}
}

void	ft_move_left(t_mapping *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			if (game->game_map[y][x] == 'P')
			{
				if (game->game_map[y][x - 1] == '0' \
				|| game->game_map[y][x - 1] == 'C' \
				|| game->game_map[y][x - 1] == 'E')
				{
					if (ft_check_count(game, game->game_map[y - 1][x]))
						return ;
					game->game_map[y][x  - 1] = 'P';
					game->game_map[y][x] = '0';
					ft_printf("Move up\n");
					return ;
				}
			}
		}
	}
}

void	ft_move_right(t_mapping *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->size.y)
	{
		x = -1;
		while (++x < game->size.x)
		{
			if (game->game_map[y][x] == 'P')
			{
				if (game->game_map[y][x + 1] == '0' \
				|| game->game_map[y][x + 1] == 'C' \
				|| game->game_map[y][x + 1] == 'E')
				{
					if (ft_check_count(game, game->game_map[y - 1][x]))
						return ;
					game->game_map[y][x + 1] = 'P';
					game->game_map[y][x] = '0';
					ft_printf("Move up\n");
					return ;
				}
			}
		}
	}
}

void	ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_mapping	*game;

	game = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(game->mlx);
			ft_printf("game\n");
		}
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			ft_move_up(game);
		if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			ft_move_down(game);
		if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			ft_move_left(game);
		if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			ft_move_right(game);
	}
}
