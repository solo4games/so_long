/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:17:20 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 21:02:28 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_sprite(t_all *all, int x, int y)
{
	int color;
	int i;
	int j;

	i = -1;
	all->temp_img = (t_datatext *)malloc(sizeof(t_datatext));
	all->temp_img->img = mlx_new_image(all->win->mlx, SIZE, SIZE);
	if (all->temp_img->img > 0)
		all->temp_img->addr = (char *)mlx_get_data_addr(all->temp_img->img, &all->temp_img->bpp,
				&all->temp_img->length, &all->temp_img->endian);
	while (++i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			color = *(int *)(all->player->addr + (j * all->player->length + 
				i * (all->player->bpp / 8)));
			if ((color & 0x00FFFFFF) == 0)
			{
				color = *(int *)(all->space->addr + (j * all->space->length +
						i * (all->space->bpp / 8)));
				if (all->pos->pos_player_y == all->pos->pos_exit_y && 
					all->pos->pos_player_x == all->pos->pos_exit_x)
				{
					color = *(int *)(all->exit_icon->addr + (j * all->exit_icon->length +
						i * (all->exit_icon->bpp / 8)));
				}
			}
			my_mlx_pixel_put(all->temp_img, i, j, color);
		}
	}
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->temp_img->img, x, y);
}

void draw_some_stuff(t_all *all)// если будет не впадлу, сделать проверку на размеры окна
{
	int x;
	int y;
	int i;
	int j;

	y = 0;
	i = -1;
	while (all->map[++i])
	{
		j = -1;
		x = 0;
		while(++j < all->pos->map_width)
		{
			if (all->map[i][j] == 'C')
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->collectible->img, x, y);
			if (all->map[i][j] == '1') //поставить нормальные текстуры
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->walls->img, x, y);
			if (all->map[i][j] == '0')
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->space->img, x, y);
			if (j == all->pos->pos_player_x && i == all->pos->pos_player_y)
				print_sprite(all, x, y);
			if (j == all->pos->pos_exit_x && i == all->pos->pos_exit_y)
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->exit_icon->img, x, y);
			x += SIZE;
		}
		y += SIZE;
	}
}

void ft_move_w_s(int key, t_all *all)
{
	int prev_x;
	int prev_y;

	prev_x = all->pos->pos_player_x * SIZE;
	prev_y = all->pos->pos_player_y * SIZE;
	if (key == 13)
	{
		if (all->map[prev_y / SIZE - 1][prev_x / SIZE] != '1')
		{
			all->pos->pos_player_y--;
			mlx_put_image_to_window(all->win->mlx, all->win->win, all->space->img, prev_x, prev_y);
			if (prev_x / SIZE == all->pos->pos_exit_x && prev_y / SIZE == all->pos->pos_exit_y)
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->exit_icon->img, prev_x, prev_y);
			print_sprite(all, all->pos->pos_player_x * SIZE, all->pos->pos_player_y * SIZE);
		}
	}
	if (key == 1)
	{
		if (all->map[prev_y / SIZE + 1][prev_x / SIZE] != '1')
		{
			all->pos->pos_player_y++;
			mlx_put_image_to_window(all->win->mlx, all->win->win, all->space->img, prev_x, prev_y);
			if (prev_x / SIZE == all->pos->pos_exit_x && prev_y / SIZE == all->pos->pos_exit_y)
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->exit_icon->img, prev_x, prev_y);
			print_sprite(all, all->pos->pos_player_x * SIZE, all->pos->pos_player_y * SIZE);
		}
	}
}

void ft_move_a_d(int key, t_all *all)
{
	int prev_x;
	int prev_y;

	prev_x = all->pos->pos_player_x * SIZE;
	prev_y = all->pos->pos_player_y * SIZE;
	if (key == 0)
	{
		if (all->map[prev_y / SIZE][prev_x / SIZE - 1] != '1')
		{
			all->pos->pos_player_x--;
			mlx_put_image_to_window(all->win->mlx, all->win->win, all->space->img, prev_x, prev_y);
			if (prev_x / SIZE == all->pos->pos_exit_x && prev_y / SIZE == all->pos->pos_exit_y)
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->exit_icon->img, prev_x, prev_y);
			print_sprite(all, all->pos->pos_player_x * SIZE, all->pos->pos_player_y * SIZE);
		}
	}
	if (key == 2)
	{
		if (all->map[prev_y / SIZE][prev_x / SIZE + 1] != '1')
		{
			all->pos->pos_player_x++;
			mlx_put_image_to_window(all->win->mlx, all->win->win, all->space->img, prev_x, prev_y);
			if (prev_x / SIZE == all->pos->pos_exit_x && prev_y / SIZE == all->pos->pos_exit_y)
				mlx_put_image_to_window(all->win->mlx, all->win->win, all->exit_icon->img, prev_x, prev_y);
			print_sprite(all, all->pos->pos_player_x * SIZE, all->pos->pos_player_y * SIZE);
		}
	}
}

int	drawing(int keycode, t_all *all)
{
	if (keycode == 13 || keycode == 1)
		ft_move_w_s(keycode, all);
	if (keycode == 0 || keycode == 2)
		ft_move_a_d(keycode, all);
	if (keycode == 53)
		my_exit_from_game();
	if (all->map[all->pos->pos_player_y][all->pos->pos_player_x] == 'C')
	{
		all->num_col--;
		all->map[all->pos->pos_player_y][all->pos->pos_player_x] = '0';
	}
	if (all->pos->pos_player_x == all->pos->pos_exit_x &&
		all->pos->pos_player_y == all->pos->pos_exit_y && all->num_col == 0)
	{
		printf("you do %d steps\n", all->step);//заменить на врайты
		my_exit_from_game();
	}
	all->step++;
	printf("step counter %d\n", all->step);//заменить на врайты
	return (0);
}

int	main(int argc, char *argv[])//Карта должна быть квадратной
{
	t_all	*all;

	argv_check(argc, argv);
	all = pars_all(argv[1]);
	if (!all)
		error_handler("malloc error\n");
	all->win = (t_win *)malloc(sizeof(t_win));
	if (!all->win)
		error_handler("malloc error\n");
	init_mlx(all->win, all);
	reading_textures(all);
	draw_some_stuff(all);
	mlx_hook(all->win->win, 2, (1L << 0), &drawing, all);
	mlx_hook(all->win->win, 17, (1L << 0), &my_exit_from_game, all);
	mlx_loop(all->win->mlx);
	return (0);
}
