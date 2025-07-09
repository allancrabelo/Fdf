/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 23:48:29 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/08 00:57:10 by aaugusto         ###   ########.fr       */
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
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

//Macros
# define WIN_W 1280
# define WIN_H 720
//Structs
typedef struct s_map
{
	int	column_x;
	int	row_y;
	int	space;
	int	min_height;
	int	max_height;
	int	limit_left;
	int	limit_right;
	int	limit_top;
	int	limiy_bottom;
}			t_map;


typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
	char	**parsed_map;
}			t_fdf;

//Windows
int		start_fdf(t_fdf *data);

//Parser
int		parser(t_fdf *data, char *map);
char	*get_map(int fd, t_fdf *map);
#endif