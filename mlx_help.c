/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:48:10 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 18:46:08 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_datatext *sprite, int x, int y, int color)
{
	char	*dst;

	dst = sprite->addr + (y * sprite->length + x * (sprite->bpp / 8));
	*(unsigned int *)dst = color;
}

int	my_exit_from_game(void)
{
	write(1, "Thank you, goodbye!\n", 20);
	exit(0);
}

void	init_mlx(t_win *w, t_all *all)
{
	w->mlx = mlx_init();
	w->win = mlx_new_window(w->mlx, all->pos->map_width * SIZE,
			all->pos->map_height * SIZE, "cub3D");
	if (!w->win)
		error_handler("malloc error\n");
	w->img = (char *)mlx_new_image(w->mlx, all->pos->map_width * SIZE,
		all->pos->map_height * SIZE);
	w->addr = (char *)mlx_get_data_addr(w->img, &(w->bpp),
			&(w->length), &(w->endian));
}
