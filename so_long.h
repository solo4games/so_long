/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrandy <lbrandy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:05:58 by lbrandy           #+#    #+#             */
/*   Updated: 2021/11/13 20:54:57 by lbrandy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./source/libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

#define SIZE 64

typedef struct s_win
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
}					t_win;

typedef struct s_pos
{
	int				map_width;
	int				map_height;
	int				pos_player_x;
	int				pos_player_y;
	int				pos_exit_x;
	int				pos_exit_y;
}					t_pos;

typedef struct s_datatext
{
	void			*img;
	char			*addr;
	int				bpp;
	int				length;
	int				endian;
	int				height;
	int				width;
}					t_datatext;

typedef struct s_all
{
	t_datatext		*collectible;
	t_datatext		*exit_icon;
	t_datatext		*player;
	t_datatext		*walls;
	t_datatext		*space;
	t_datatext		*temp_img;
	t_win			*win;
	t_pos			*pos;
	char			**map;
	int				num_col;
	int				step;
}					t_all;

void				my_mlx_pixel_put(t_datatext *sprite, int x, int y, int color);
int					raycasting(t_all *all);
void				draw_frame(t_all *all);
void				reading_textures(t_all *all);
void				init_mlx(t_win *w, t_all *all);
int					argv_check(int argc, char **argv);
t_all				*pars_all(char *name_of_file);
void				skip(char **s, int flag);
void				pars_file(t_list **list, t_all *all);
void				fill_map(t_list *list, t_all *all);
t_pos				*pars_map(t_list *list, t_all *all);
char				**copy_map(t_pos *p, t_all *all);
void				free_new_map(t_pos *p, char **new_map);
void				init_dir(t_pos *pos, char temp);
void				init_pos(t_all *all, t_pos *pos);
void				check_up_down(char **map, int i, int h);
void				check_boundary(t_all *all, char **map, t_pos *pos);
int					max_width_map(char **map);
void				flood_fill(char **map, t_pos *p, int x, int y);
void				flood(t_pos *pos, t_all *all);
void				skip_spaces(char **s);
void				check_xpm(char *s);
void				error_handler(char *str);
void				ft_lstfree_cont(void *content);
int					my_exit_from_game(void);
void				screen_save(t_all *all, int argc);
int					ft_press_but(int keycode, t_all *all);
int					ft_release_but(int keycode, t_all *all);
int					drawing(int keycode, t_all *all);
int					len_number(char *s, int flag);
void				ft_filling_map(t_list *list, t_all *all, int count);

#endif
