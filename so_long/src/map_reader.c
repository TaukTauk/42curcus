/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:09:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/09 15:53:04 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_size_map(char *filename)
{
	int		fd;
	int		line;
	char	*str;

	line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error\n");
		close(fd);
		return (1);
	}
	str = get_next_line(fd);
	line++;
	while (str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
			line++;
	}
	return (line);
}

char	*ft_strdup_sl(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	i = ft_strlen(s);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}


char	**ft_making_map(char **av)
{
	int			fd;
	char		*str;
	int			i;
	char		**map;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error\n");
		close(fd);
		return (NULL);
	}
	map = (char **)malloc(sizeof(char *) * (ft_size_map(av[1]) + 1));
	str = get_next_line(fd);
	i = 0;
	while (str != NULL)
	{
		map[i++] = ft_strdup_sl(str);
		free(str);
		str = get_next_line(fd);
	}
	map[i] = 0;
	close(fd);
	return (map);
}

int	ft_char_check(char str, char c)
{
	if (str == c)
		return (1);
	return (0);
}

t_mapping	ft_init_mapping(void)
{
	t_mapping	new;

	new.num_player = 0;
	new.num_collectible = 0;
	new.num_exit = 0;
	new.size.x = 0;
	new.size.y = 0;
	new.valid = 0;
	return (new);
}
