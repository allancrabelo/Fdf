/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:48:29 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/07 02:16:38 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"

//Macros
# define WIN_W 1280
# define WIN_H 720
//Structs
typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

//Utils
void	ft_putstr(char *str);

//Windows
int		start_fdf(t_fdf *data);

#endif