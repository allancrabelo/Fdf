/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 00:23:19 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/07 02:14:47 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;

/* 	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <map file>\n");
		return (1);
	} */
	if (start_fdf(&data) == -1)
		return (1);
	return (0);
}