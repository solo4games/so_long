/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:05:41 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 15:30:33 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pars_file(t_list **list, t_all *all)
{
	//t_list	*tmp;

	all->pos = pars_map(*list, all);
	ft_lstclear(list, ft_lstfree_cont);
}
