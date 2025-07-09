/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 18:31:22 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/08 00:53:45 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	replace_newline(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}
int	parser(t_fdf *data, char *map_name)
{
	int		fd;
	char	*map;
	
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: Failed to open map\n", 2);
		return (-1);
	}
	data->map = malloc(sizeof(t_map));
	if(!data->map)
		return (-1);
	map = get_map(fd, data);
	if (!map)
		return (-1);
	ft_striteri(map, replace_newline);
	data->parsed_map = ft_split(map, ' ');
	free(map);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Failed to close map\n", 2);
		return (-1);
	}
	return (0);
}
