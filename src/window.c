/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 01:56:09 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/08 00:19:27 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	start_fdf(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_putstr_fd("Error: Unable to establish connection with the X server.\n", 2);
		return (1);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W , WIN_H, "Fdf");
	if (data->win_ptr == NULL)
	{
		ft_putstr_fd("Error: Failed to create window.\n", 2);
		return (1);
	}
	mlx_loop(data->mlx_ptr);
	return (0);
}
