/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:06:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/13 18:31:48 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
#include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIN_W 1280
# define WIN_H 720
# define BLACK 0x00000000

typedef struct s_pt
{
	float_t	x;
	float_t	y;
	float_t	z;
	int		color;
}	t_pt;


typedef struct s_map
{
	t_pt	*pt_arr;
	int		y_dim;
	int		x_dim;
}	t_map;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	char	**parsed_file;
	t_map	*original_map;
}	t_data;

//Hooks
int	start_mlx(t_data *data);
int	close_app(t_data *data);

//File Handling
int		parse_file(t_data *data, char *filename);
int		count_cols(char *string);
char	*get_file(int fd, t_data *data);
int		lines_consistent(int cols, t_data *data);
void	append_line_to_file(char **line, char **file);
void	free_str_arr(char **str);

//Draw
void	render_background(t_img *img, int color);
void	draw_map(t_img *img, t_map *map, t_pt offset);
void	img_pix_put(t_img *img, t_pt pt);

//Operations
t_pt	vec_add(t_pt pt1, t_pt pt2);

//Lines
int		draw_line(t_img *img, t_pt start, t_pt end);
t_pt	vec_sub(t_pt pt1, t_pt	pt2);

//Colors
int		get_color(t_pt cur, t_pt start, t_pt end, t_pt delta);

#endif