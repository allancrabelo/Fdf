/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:06:22 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 19:34:57 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	draw_line_low(t_img *img, t_pt start, t_pt end)
{
	int		y_variance;
	t_pt	delta;
	t_pt	current;
	int		error;

	delta = vec_sub(end, start);
	y_variance = 1;
	if (delta.y < 0)
		y_variance = -1;
	delta.y = fabsf(delta.y);
	error = 2 * delta.y - delta.x;
	current = start;
	while (current.x < end.x)
	{
		img_pix_put(img, current);
		if (error > 0)
			current.y += y_variance;
		if (error > 0)
			error = error + (2 * (delta.y - delta.x));
		else
			error = error + 2 * delta.y;
		current.color = get_color(current, start, end, delta);
		current.x++;
	}
	return (0);
}

int	draw_line_high(t_img *img, t_pt start, t_pt end)
{
	int		x_variance;
	t_pt	delta;
	t_pt	current;
	int		error;

	delta = vec_sub(end, start);
	x_variance = 1;
	if (delta.x < 0)
		x_variance = -1;
	delta.x = fabsf(delta.x);
	error = 2 * delta.x - delta.y;
	current = start;
	while (current.y < end.y)
	{
		img_pix_put(img, current);
		if (error > 0)
			current.x += x_variance;
		if (error > 0)
			error = error + (2 * (delta.x - delta.y));
		else
			error = error + 2 * delta.x;
		current.color = get_color(current, start, end, delta);
		current.y++;
	}
	return (0);
}

int	draw_line(t_img *img, t_pt start, t_pt end)
{
	if (fabsf(end.y - start.y) < fabsf(end.x - start.x))
	{
		if (start.x > end.x)
			return (draw_line_low(img, end, start));
		return (draw_line_low(img, start, end));
	}
	if (start.y > end.y)
		return (draw_line_high(img, end, start));
	return (draw_line_high(img, start, end));
	return (1);
}
