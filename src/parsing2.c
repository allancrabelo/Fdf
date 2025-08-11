/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 12:39:02 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/11 13:52:13 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"

char	*get_file(int fd, t_data *data)
{
	char	*file;
	char	*line;
	int		cols;

	line = "";
	file = malloc(sizeof(char));
	if (file == NULL)
		return (NULL);
	file[0] = '\0';
	data->map->y_dim = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			cols = count_cols(line);
			if (!line_consistent(cols, data))
				return (NULL);
			data->map->x_dim = cols;
			data->map->y_dim += 1;
			append_line_to_file(&line, &file);
		}
	}
	return (file);
}

int	line_consistent(int	cols, t_data *data)
{
	if (data->map->y_dim != 0 && data->map->x_dim != cols)
		return (ft_printf( BOLD SRED "[ERROR] Line inconsistent\n" SRESET), 0);
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