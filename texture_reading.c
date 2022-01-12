/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_reading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 13:30:58 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 19:10:51 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_all_text(t_all *all, char *texname, t_datatext *tex)
{
	tex->img = mlx_xpm_file_to_image(all->win->mlx, texname,
			&tex->width, &tex->height);
	if (tex->img > 0)
		tex->addr = (char *)mlx_get_data_addr(tex->img, &tex->bpp,
				&tex->length, &tex->endian);
	else
		error_handler("not correct path or extension of file\n");
}

void	reading_textures(t_all *all)
{
	all->player = (t_datatext *)malloc(sizeof(t_datatext));
	all->exit_icon = (t_datatext *)malloc(sizeof(t_datatext));
	all->collectible = (t_datatext *)malloc(sizeof(t_datatext));
	all->space = (t_datatext *)malloc(sizeof(t_datatext));
	all->walls = (t_datatext *)malloc(sizeof(t_datatext));
	if (!all->player || !all->exit_icon || !all->collectible ||
		!all->space || !all->walls)
		error_handler("malloc error\n");
	init_all_text(all , "./source/sprites/player.xpm", all->player);
	init_all_text(all, "./source/sprites/exit.xpm", all->exit_icon);
	init_all_text(all, "./source/sprites/invader.xpm", all->collectible);
	init_all_text(all, "./source/sprites/dalle-64t.xpm", all->walls);
	init_all_text(all, "./source/sprites/bottom-64.xpm", all->space);
}
