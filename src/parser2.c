/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:24:34 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/08 00:57:55 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	append_line_to_map(char **line, char **map)
{
	char *tmp;

	tmp = *map;
	*map = ft_strjoin(tmp, *line);
	free(tmp);
	free(*line);
	*line = "";
}

int	lines_verification(int cols, t_fdf *map)
{
	if (map->map->row_y !=  0 && map->map->column_x != cols)
	{
		ft_putstr_fd("Error: Found wrong line length.", 2);
		return (0);
	}
	return (1);
}

char	*get_map(int fd, t_fdf *map)
{
	char	*file;
	char	*line;
	int		cols;

	file = malloc(sizeof(char));
	line = "";
	if (!file)
		return (NULL);
	file[0] = '\0';
	map->map->row_y = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (!lines_verification(cols, map));
			return (NULL);
		map->map->column_x = cols;
		map->map->row_y += 1;
		append_line_to_map(&line, &map);
	}
	return (file);
}
