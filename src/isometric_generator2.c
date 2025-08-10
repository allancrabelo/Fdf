/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_generator2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:24:23 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 21:20:38 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_x(t_map *map, float_t angle)
{
	t_matrix	rot_x;

	rot_x = (t_matrix){
		1, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle)};
	transform_map(map, rot_x);
}

void	rotate_y(t_map *map, float_t angle)
{
	t_matrix	rot_y;
	
	rot_y = (t_matrix) {
		cos(angle), 0, sin(angle),
		0, 1, 0,
		-sin(angle), 0, cos(angle)};
	transform_map(map, rot_y);
}

void	set_size(t_map *map)
{
	int		i;
	t_pt	*cur;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->pt_arr + i;
		if (cur->x < map->min_x)
			map->min_x = cur->x;
		if (cur->x > map->max_x)
			map->max_x = cur->x;
		if (cur->y < map->min_y)
			map->min_y = cur->y;
		if (cur->y > map->max_y)
			map->max_y = cur->y;
		i++;
	}
}

void	autoscale_generator(t_map *map)
{
	float_t	scale_x;
	float_t	scale_y;

	map->min_x = 0;
	map->max_x = 0;
	map->min_y = 0;
	map->max_y = 0;
	set_size(map);
	scale_x = (WIN_W / 2 - 30) / fmaxf(abs(map->max_x), abs(map->min_x));
	scale_y = (WIN_H / 2 - 30) / fmaxf(abs(map->max_y), abs(map->min_y));
	zoom(map, fminf(scale_x, scale_y));
}