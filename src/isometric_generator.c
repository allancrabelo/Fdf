/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_generator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:38:36 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 21:19:25 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric_generator(t_map *map)
{
	rotate_x(map, -M_PI_2);
	rotate_y(map, M_PI_4);
	rotate_x(map, ISO);
}

void	zoom(t_map	*map, float_t factor)
{
	t_matrix	scale;
	
	scale = (t_matrix){factor, 0, 0, 0, factor, 0, 0, 0, factor};
	transform_map(map, scale);
}

t_map	*transform_map(t_map *map, t_matrix mat)
{
	int		i;
	t_pt	*cur;

	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->pt_arr + i;
		*cur = mat_mult(mat, *cur);
		i++;
	}
	map->base_i = mat_mult(mat, map->base_i);
	map->base_j = mat_mult(mat, map->base_j);
	map->base_k = mat_mult(mat, map->base_k);
	return (map);
}