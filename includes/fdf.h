/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 01:06:06 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 21:20:08 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// Macros
# define WIN_W 1280
# define WIN_H 720
# define BLACK	0x00000000
# define WHITE	0x00FFFFFF
# define GREEN	0x0000FF00
# define DBLUE	0x00000066

# define GROUND_COLOR	GREEN
# define HIGH_COLOR		WHITE
# define LOW_COLOR		DBLUE

# define M_PI_2	1.57079632679489661923
# define M_PI_4	0.7853981633974483
# define ISO	0.6154

// Includes
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

// Structs
typedef struct s_pt
{
	float_t	x;
	float_t	y;
	float_t	z;
	int		color;
}				t_pt;

typedef struct s_map
{
	t_pt	*pt_arr;
	int		x_dim;
	int		y_dim;
	int		min_h;
	int		max_h;
	t_pt	base_i;
	t_pt	base_j;
	t_pt	base_k;
	int		space;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
}				t_map;

typedef	struct s_matrix
{
	float_t	a11;
	float_t	a12;
	float_t	a13;
	float_t	a21;
	float_t	a22;
	float_t	a23;
	float_t	a31;
	float_t	a32;
	float_t	a33;
}				t_matrix;


typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;


typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	char	**parsed_file;
	t_map	*original_map;
}				t_data;

// [Functions]
// Window:
int		start_mlx(t_data *data);
int		close_app(t_data *data);

// Key Hooks:

// Image:
void	render_background(t_img *img, int color);
void	img_pix_put(t_img *img, t_pt pt);

// Lines:
int		draw_line(t_img *img, t_pt start, t_pt end);
int		draw_line_high(t_img *img, t_pt start, t_pt end);
int		draw_line_low(t_img *img, t_pt start, t_pt end);
void	draw_map(t_img *img, t_map *map, t_pt offset);

// Utils
t_pt	vec_add(t_pt pt1, t_pt pt2);
t_pt	vec_sub(t_pt pt1, t_pt pt2);

// Parsing
int		line_consistent(int	cols, t_data *data);
char	*get_file(int fd, t_data *data);
int		parser(t_data *data, char *file);
int		count_cols(char *s);
void	replace_newline(unsigned int i, char *s);
void	free_str_arr(char **str_arr);
void	append_line_to_file(char **line, char **file);

// Map Generator
t_map	*map_generator(t_data *data);
void	set_height_range(t_map *map, t_pt *cur);
void	fill_map(t_data *data, t_map *map);
t_map	*save_map(t_data *data);

// Colors
int		get_height_gradient(t_pt cur, t_pt start, t_pt end);
int		color_channel(int start, int end, float_t percentage);
float_t	get_percentage(int start, int end, int cur);
void	set_point_colors(t_map *map);
int		get_color(t_pt cur, t_pt start, t_pt end, t_pt delta);

// Isometric Generator
void	isometric_generator(t_map *map);
void	rotate_x(t_map *map, float_t angle);
t_pt	mat_mult(t_matrix mat, t_pt	pt);
t_map	*transform_map(t_map *map, t_matrix mat);
void	rotate_y(t_map *map, float_t angle);
void	autoscale_generator(t_map *map);
void	zoom(t_map	*map, float_t factor);
void	set_size(t_map *map);
#endif