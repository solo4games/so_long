/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:28:07 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 21:09:55 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_list	*skip_empty_lines(t_list *tmp)
{
	char	*s;

	while (tmp)
	{
		s = tmp->content;
		if (s)
		{
			while (*s == ' ')
				s++;
			if (*s != '\0')
				break ;
		}
		tmp = tmp->next;
	}
	return (tmp);
}

static int	check_str(char *s)
{
	if (!*s)
		return (1);
	while (*s)
	{
		if (*s != ' ')
			return (0);
		s++;
	}
	return (0);
}

static void	check_trash(t_list *map)
{
	int	count;

	count = 0;
	if (map)
	{
		while (map)
		{
			count++;
			map = map->next;
		}
	}
	else
		return ;
	if (count > 1)
		error_handler("trash in file\n");
}

void	fill_map(t_list *list, t_all *all)
{
	int		count;
	t_list	*start_map;
	size_t	len;

	count = 0;
	list = skip_empty_lines(list);
	start_map = list;
	len = ft_strlen(start_map->content);
	while (start_map)
	{
		if (start_map->content)
		{
			if (len != ft_strlen(start_map->content))
				error_handler("map is not rectangular\n");
			if (!start_map || check_str(start_map->content))
				break ;
			count++;
			start_map = start_map->next;
		}
		else
			break ;
	}
	check_trash(start_map);
	all->map = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!all->map)
		error_handler("malloc error\n");
	ft_filling_map(list, all, count);
}

t_pos	*pars_map(t_list *list, t_all *all)
{
	t_pos	*p;

	p = (t_pos *)malloc(sizeof(t_pos));
	if (!p)
		error_handler("malloc error\n");
	fill_map(list, all);
	init_pos(all, p);
	check_boundary(all, all->map, p);
	flood(p, all);
	return (p);
}
