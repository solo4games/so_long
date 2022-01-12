/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_part_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:10:08 by lbrandy           #+#    #+#             */
/*   Updated: 2022/01/03 16:41:47 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	pos_opening(t_pos *pos)
{
	pos->map_height = -1;
	pos->map_width = -1;
	pos->pos_exit_x = -1;
	pos->pos_exit_y = -1;
	pos->pos_player_x = -1;
	pos->pos_player_y = -1;
}

static int	init_params(t_pos *pos, char sym, int i, int j)
{
	if (sym == 'E')
	{
		if (pos->pos_exit_x != -1)
			error_handler("duplicate data");
		pos->pos_exit_x = j;
		pos->pos_exit_y = i;
	}
	if (sym == 'P')
	{
		if (pos->pos_player_x != -1)
			error_handler("duplicate data");
		pos->pos_player_x = j;	
		pos->pos_player_y = i;
	}
	return (0);// вроде инт не нужен
}

static void	check_sym(t_all *all, t_pos *pos, int i, int j)
{
	if (ft_strchr("01CEP", all->map[i][j]) == NULL)
		error_handler("trash in file\n");
	if (all->map[i][j] == 'E' || all->map[i][j] == 'P' ||
		all->map[i][j] == 'C')
	{
		init_params(pos, all->map[i][j], i, j);
		if (all->map[i][j] == 'E' || all->map[i][j] == 'P')
			all->map[i][j] = '0';
		if (all->map[i][j] == 'C')
			all->num_col++;
	}
}

void	init_pos(t_all *all, t_pos *pos)
{
	int		i;
	int		j;

	i = 0;
	pos_opening(pos);
	all->num_col = 0;
	while (all->map[i])
	{
		j = 0;
		while (all->map[i][j])
		{
			check_sym(all, pos, i, j);
			j++;
		}
		i++;
	}
	if (pos->pos_exit_x == -1 || pos->pos_player_x == -1 || all->num_col == 0)
		error_handler("something not found\n");
	pos->map_height = i;
}

void	check_up_down(char **map, int i, int h)
{
	while (map[0][i])
	{
		if (map[0][i] == '1')
			i++;
		else
			error_handler("bad boundaries\n");
	}
	i = 0;
	while (map[h - 1][i])
	{
		if (map[h - 1][i] == '1')
			i++;
		else
			error_handler("bad boundaries\n");
	}
}

void	check_boundary(t_all *all, char **map, t_pos *pos)
{
	int	i;
	int	h;

	i = 0;
	(void)all;
	h = pos->map_height;
	check_up_down(map, i, h);
	i = 0;
	while (map[i])
	{
		if (map[i][0] == '1')
			i++;
		else
			error_handler("bad boundaries\n");
	}
	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 1] == '1')
			i++;
		else
			error_handler("bad boundaries\n");
	}
}
