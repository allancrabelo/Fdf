/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:23:41 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 19:11:34 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float_t	get_percentage(int start, int end, int cur)
{
	float_t	position;
	float_t	delta;
	
	delta = end - start;
	if (delta == 0)
		return (1.0);
	position = cur - start;
	return (position / delta);
}
int	color_channel(int start, int end, float_t percentage)
{
	int	color_channel;

	color_channel = (1 - percentage) * start + percentage * end;
	return (color_channel);
}

int	get_color(t_pt cur, t_pt start, t_pt end, t_pt delta)
{
	int		red;
	int		green;
	int		blue;
	float_t	percentage;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = get_percentage(start.x, end.x, cur.x);
	else
		percentage = get_percentage(start.y, end.y, cur.y);
	red = color_channel((start.color >> 16) & 0xFF,
		(end.color >> 16) & 0xFF, percentage);
	green = color_channel((start.color >> 8) & 0xFF,
		(end.color >> 8) & 0xFF, percentage);
	blue = color_channel(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

int	get_height_gradient(t_pt cur, t_pt start, t_pt end)
{
	int		red;
	int		blue;
	int		green;
	float_t	percentage;

	percentage = get_percentage(fabsf(start.z), fabsf(end.z), fabsf(cur.z));
	red = color_channel((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0XFF, percentage);
	green = color_channel((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);	
	blue = color_channel(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}