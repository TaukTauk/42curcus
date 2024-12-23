/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talin <talin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:42:28 by talin             #+#    #+#             */
/*   Updated: 2024/11/19 11:44:30 by talin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parse_str(char *str, t_list **lst)
{
	int		i;
	char	**res;

	res = ft_split(str, ' ');
	if (!res)
		ft_handle_error(lst);
	i = -1;
	while (res[++i])
		ft_add_node(lst, res[i], res);
	i = -1;
	while (res[++i])
		free(res[i]);
	free(res);
}

void	ft_create_list(char	*str, t_list **lst)
{
	if (!ft_handle_outsider(str))
		ft_handle_error(lst);
	if (ft_strchr(str, ' '))
		ft_parse_str(str, lst);
	else
		ft_add_node_two(lst, str);
}

t_stack	*ft_lst_to_stack(t_list **lst, t_stack *a)
{
	t_list	*tmp;
	int		len;

	tmp = *lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	a->arr = (int *)malloc(sizeof(int) * len);
	if (!a->arr)
		ft_handle_error(lst);
	tmp = *lst;
	a->len = len;
	len = 0;
	while (tmp)
	{
		a->arr[len++] = tmp->content;
		tmp = tmp->next;
	}
	ft_lstclear(lst, &delete);
	return (a);
}

t_stack	*ft_create_stack(int ac, char **av)
{
	t_list	*lst;
	t_stack	*a;
	int		i;

	i = 0;
	lst = NULL;
	while (++i < ac)
		ft_create_list(av[i], &lst);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (!a)
		ft_handle_error(&lst);
	return (ft_lst_to_stack(&lst, a));
}
