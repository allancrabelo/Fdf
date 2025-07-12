/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:24:10 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/12 17:13:37 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./fdf <MAP FILE>\n", 2);
		return (1);
	}
//	if (parse_file(&data, argv[1]) == 1)
//		return (1);
	if (start_mlx(&data) == 1)
		return (-1);
	return (0);
}