/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:03:40 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/11 12:46:09 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (ft_printf(BOLD SCYAN "Usage: ./fdf [Map File]\n" SRESET), 2);
	if (parser (&data, argv[1]) == 1)
		return (1);
	map_generator(&data);
	isometric_generator(data.map);
	autoscale_generator(data.map);
	if (start_mlx(&data) == 1)
		return (1);
	return (0);
}
