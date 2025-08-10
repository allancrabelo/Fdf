/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:50:10 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 19:29:10 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*map_generator(t_data *data)
{
	t_map	*map;
	
	map = data->map;
	map->min_h = 0;
	map->max_h = 0;
	map->base_i = (t_pt){1, 0, 0, 0x0};
	map->base_j = (t_pt){0, 1, 0, 0x0};
	map->base_k = (t_pt){0, 0, 1, 0x0};
	map->pt_arr = malloc (sizeof(t_pt) * map->x_dim * map->y_dim);
	if (map->pt_arr == NULL)
		return (NULL);
	map->space = 10;
	fill_map(data, map);
	set_point_colors(map);
	save_map(data);
	return (map);
}

t_map *save_map(t_data *data)
{
	int		i;
	t_pt	*cur;

	data->original_map = malloc(sizeof(t_map));
	if (data->original_map == NULL)
		return (NULL);
	data->original_map->pt_arr = malloc(data->map->x_dim
			* data->map->y_dim * sizeof(t_pt));
	if (data->original_map->pt_arr == NULL)
		return (NULL);
	i = 0;
	while (i < data->map->x_dim * data->map->y_dim)
	{
		cur = data->map->pt_arr + i;
		*(data->original_map->pt_arr + i) = *cur;
		i++;
	}
	return (data->original_map);
}

void	fill_map(t_data *data, t_map *map)
{
	int		i;
	int		j;
	t_pt	*cur;
	t_pt	pt;

	pt.z = 0;
	pt.y = -map->space * map->y_dim / 2;
	i = 0;
	while (i < map->y_dim)
	{
		pt.x = -map->space * map->x_dim / 2;
		j = 0;
		while (j < map->x_dim)
		{
			cur = map->pt_arr + i * map->x_dim + j;
			*cur = pt;
			cur->z = ft_atoi(data->parsed_file[i * map->x_dim + j]);
			set_height_range(map, cur);
			cur->color = GROUND_COLOR;
			pt.x += map->space;
			j++;
		}
		pt.y += map->space;
		i++;
	}
}

void set_height_range(t_map *map, t_pt *cur)
{
	if (cur->z < map->min_h)
		map->min_h = cur->z;
	if (cur->z > map->max_h)
		map->max_h = cur->z;
}

void	set_point_colors(t_map *map)
{
	t_pt	ground;
	t_pt	max;
	t_pt	min;
	int		i;
	t_pt	*cur;

	ground = (t_pt){0, 0, 0, GROUND_COLOR};
	max = (t_pt){0, 0, map->max_h, HIGH_COLOR};
	min = (t_pt){0, 0, map->min_h, LOW_COLOR};
	i = 0;
	while (i < map->x_dim * map->y_dim)
	{
		cur = map->pt_arr + i;
		if (cur->z > 0)
			cur->color = get_height_gradient(*cur, ground, max);
		if (cur->z < 0)
			cur->color = get_height_gradient(*cur, ground, min);
		i++;
	}
}