/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:54:46 by talin             #+#    #+#             */
/*   Updated: 2024/10/01 11:44:07 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

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

# define SPECIFIER	"cspdiuxX%"

char		*ft_strchr(char *s, int c);
int			ft_isdigit(int c);
int			ft_atoi(char *str);
t_format	ft_newformat(void);
int			ft_print_format(t_format new, va_list ptr);
int			ft_strlen(char *str);
int			ft_putnstr(char *str, int size);
int			ft_putnchar(int c, int size);
char		*ft_strdup(char *s);
int			ft_printf_str(t_format new, va_list ptr);
int			ft_printf_char(t_format new, va_list ptr);
#endif