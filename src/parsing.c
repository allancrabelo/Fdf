/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 11:58:12 by aaugusto          #+#    #+#             */
/*   Updated: 2025/08/10 13:33:33 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../includes/colors.h"

void	replace_newline(unsigned int i, char *s)
{
	(void)i;
	if (*s == '\n')
		*s = ' ';
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free (str_arr);
}

int	count_cols(char *s)
{
	int		cols;
	char	*tmp;
	char	**split;

	tmp = ft_strdup(s);
	cols = 0;
	ft_striteri(tmp, replace_newline);
	split = ft_split(tmp, ' ');
	free(tmp);
	while (split[cols] != NULL)
		cols++;
	free_str_arr(split);
	return (cols);
}

int	parser(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_printf(BOLD SRED "[ERROR] Failed to open file\n" SRESET), 1);
	data->map = malloc(sizeof(t_map));
	if (data->map == NULL)
		return (1);
	file = get_file(fd, data);
	if (file == NULL)
		return (1);
	ft_striteri(file, replace_newline);
	data->parsed_file = ft_split(file, ' ');
	free(file);
	if (close(fd) == -1)
		return (ft_printf(BOLD SRED "Failed to close \n" SRESET), 1);
	return (0);
}
