/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 00:20:43 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/13 00:20:43 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	img_pix_put(t_img *img, t_pt pt)
{
	int		x;
	int		y;
	char	*pixel;

	x = round(pt.x);
	y = round(pt.y);
	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	pixel = img->addr + y * img->line_len + x * (img->bpp/8);
	*(int *)pixel = pt.color;
}
void	draw_map(t_img *img, t_map *map, t_pt offset)
{
	int		i;
	t_pt	*cur;
	t_pt	pt;
	t_pt	neighbour_right;
	t_pt	neighbour_down;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->pt_arr + 1;
		pt = vec_add(*cur, offset);
		if (i % map->x_dim != map->x_dim - 1)
		{
			neighbour_right = vec_add(*(cur + 1), offset);
			draw_line(img, pt, neighbour_right);
		}
		if (i < map->x_dim * map->y_dim - map->x_dim)
		{
			neighbour_down = vec_add(*(cur + map->x_dim), offset);
			draw_line(img, pt, neighbour_down);
		}
		i++;
	}
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_H)
	{
		j = 0;
		while (j < WIN_W)
		{
			img_pix_put(img, (t_pt){j, i, 0, color});
			j++;
		}
		i++;
	}
}