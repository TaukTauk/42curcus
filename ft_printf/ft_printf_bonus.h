/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:46 by talin             #+#    #+#             */
/*   Updated: 2024/09/30 09:34:53 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>

typedef struct t_format
{
	int		plus;
	int		minus;
	int		space;
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		neg_prec;
	int		sharp;
	char	specifier;
}	t_format;

char	*ft_strchr(char *s, int c);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
t_format	ft_newformat(void);
#endif