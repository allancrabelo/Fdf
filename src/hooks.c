/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:30:09 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/12 23:59:57 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	loop_hook(t_data *data)
{
	if (!data->win_ptr)
		return (1);
	//render_background(&data->img, BLACK);
	
	return (0);
}

int	key_hook1(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		close_app(data);
	return (0);
}

int	close_app(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->map);
	free(data->original_map->pt_arr);
	free(data->original_map);
	free_str_arr(data->parsed_file);
	exit(0);
	return (0);
}

int	start_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		ft_putstr_fd("Error: Failed to set up the connection to the server\n", 2);
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_W, WIN_H, "Fdf");
	if (data->win_ptr == NULL)
		ft_putstr_fd("Error: Failed to create a new window\n", 2);
	if (data->win_ptr == NULL)
		return (1);
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
					&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->mlx_ptr, loop_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, close_app, data);
	mlx_hook(data->win_ptr, KeyPress, 1, key_hook1, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
