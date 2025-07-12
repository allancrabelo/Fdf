/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:01:27 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/12 16:45:13 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*get_file(int fd, t_data *data)
{
	char	*file;
	char	*line;
	int		cols;

	cols = 0;
	line = "";
	file = malloc(sizeof(char));
	if (!file)
		return	(NULL);
	file[0] = '\0';
	data->map->y_dim = 0;
	while(line)
	{
		line = get_next_line(fd);
		if (!line)
		{
			cols = count_cols(line);
			if (!lines_consistent(cols, data))
				return(NULL);
			data->map->x_dim = cols;
			data->map->y_dim += 1;
			append_line_to_file(&line, &file);
		}
	}
	return (file);
}

int	lines_consistent(int cols, t_data *data)
{
	if (data->map->y_dim != 0 && data->map->x_dim != cols)
	{
		ft_putstr_fd("Error: inconsistent line length detected.\n", 2);
		return (0);
	}
	return (1);
}

void	append_line_to_file(char **line, char **file)
{
	char	*tmp;

	tmp = *file;
	*file = ft_strjoin(tmp, *line);
	free(tmp);
	free(*line);
	*line = "";
}