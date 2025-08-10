/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:57:37 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 21:22:21 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pt	vec_add(t_pt pt1, t_pt pt2)
{
	t_pt	sum;

	sum.x = pt1.x + pt2.x;
	sum.y = pt1.y + pt2.y;
	sum.z = pt1.z + pt2.z;
	sum.color = pt1.color;
	return (sum);
}

t_pt	vec_sub(t_pt pt1, t_pt pt2)
{
	t_pt	diff;

	diff.x = pt1.x - pt2.x;
	diff.y = pt1.y - pt2.y;
	diff.z = pt1.z - pt2.z;
	diff.color = pt1.color;
	return (diff);
}

t_pt	mat_mult(t_matrix mat, t_pt	pt)
{
	t_pt	res;

	res.x = pt.x * mat.a11 + pt.y * mat.a21 + pt.z * mat.a31;
	res.y = pt.x * mat.a12 + pt.y * mat.a22 + pt.z * mat.a32;
	res.z = pt.x * mat.a13 + pt.y * mat.a23 + pt.z * mat.a33;
	res.color = pt.color;
	return (res);
}