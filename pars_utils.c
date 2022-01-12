/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:24:42 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 15:24:59 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstfree_cont(void *content)
{
	if (content)
		free(content);
}

void	ft_filling_map(t_list *list, t_all *all, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		all->map[i] = ft_strdup(list->content);
		if (!all->map[i])
			error_handler("malloc error\n");
		list = list->next;
		i++;
	}
}