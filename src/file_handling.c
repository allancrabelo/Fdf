/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <<aaugusto@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 15:32:34 by aaugusto          #+#    #+#             */
/*   Updated: 2025/07/12 16:42:06 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	replace_newline(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

void	free_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
int	count_cols(char *string)
{
	int		cols;
	char	*tmp;
	char	**split;

	cols = 0;
	tmp = ft_strdup(string);
	ft_striteri(tmp, replace_newline);
	split = ft_split(tmp, ' ');
	free(tmp);
	while (split[cols])
		cols++;
	free_str_arr(split);
	return (cols);
}

int	parse_file(t_data *data, char *filename)
{
	int		fd;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: File not found or permission denied.\n", 2);
		return (1);
	}
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (1);
	file = get_file(fd, data);
	if (!file)
		return (1);
	ft_striteri(file, replace_newline);
	data->parsed_file = ft_split(file, ' ');
	free(file);
	if (close(fd) == -1)
	{
		ft_putstr_fd("Error: Failed to close file\n", 2);
		return (1);
	}
	return (0);
}
