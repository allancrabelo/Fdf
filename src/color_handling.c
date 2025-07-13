/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:39:14 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/13 18:20:35 by aaugusto         ###   ########.fr       */
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

int	calc_color_channel(int start,int end, float_t percentage)
{
	int	color_channel;

	color_channel = (1 - percentage) * start + percentage * end;
	return (color_channel);
}

int	get_color(t_pt cur, t_pt start, t_pt end, t_pt delta)
{
	float_t	percentage;
	int		red;
	int		green;
	int		blue;

	if (cur.color == end.color)
		return (cur.color);
	if (delta.x > delta.y)
		percentage = get_percentage(start.x, end.x, cur.x);
	else
		percentage = get_percentage(start.y, end.y, cur.y);
	red = calc_color_channel((start.color >> 16) & 0xFF,
					(end.color >> 8) & 0xFF, percentage);
	green = calc_color_channel((start.color >> 8) & 0xFF,
					(end.color >> 8) & 0xFF, percentage);
	blue = calc_color_channel(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
