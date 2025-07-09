/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaugusto <aaugusto@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:13:56 by aaugusto          #+#    #+#             */
/*   Updated: 2025/04/09 09:59:10 by aaugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_charcount(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static int	ft_occurence(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			word_count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (word_count);
}

static void	*ft_free(char **splitted_s, size_t i)
{
	while (i--)
		free(splitted_s[i]);
	free(splitted_s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	len = ft_occurence(s, c);
	res = (char **)malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (j < len)
	{
		while (s[i] == c)
			i++;
		res[j] = ft_substr(s, i, ft_charcount(s, c, i));
		if (!res[j++])
			return (ft_free(res, j));
		i += ft_charcount(s, c, i);
	}
	res[j] = NULL;
	return (res);
}
/* int	main(void)
{
	char **result;
	int i;

	char *str1 = "42 School Porto";
	char delimiter1 = ' ';
	printf("Test 1: \"%s\" (delimiter: '%c')\n", str1, delimiter1);
	result = ft_split(str1, delimiter1);
	i = 0;
	while (result[i])
	{
		printf("Part %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	printf("\n");


	char *str2 = "42           School     Porto";
	char delimiter2 = ' ';
	printf("Test 2: \"%s\" (delimiter: '%c')\n", str2, delimiter2);
	result = ft_split(str2, delimiter2);
	i = 0;
	while (result[i])
	{
		printf("Part %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	printf("\n");

	char *str3 = "---42--School---Porto---";
	char delimiter3 = '-';
	printf("Test 3: \"%s\" (delimiter: '%c')\n", str3, delimiter3);
	result = ft_split(str3, delimiter3);
	i = 0;
	while (result[i])
	{
		printf("Part %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	printf("\n");

	char *str4 = "";
	char delimiter4 = ' ';
	printf("Test 4: \"%s\" (delimiter: '%c')\n", str4, delimiter4);
	result = ft_split(str4, delimiter4);
	if (!result[0])
		printf("Result: (Empty String)\n");
	free(result);
	printf("\n");

	char *str5 = ";;;;;;;";
	char delimiter5 = ';';
	printf("Test 5: \"%s\" (delimiter: '%c')\n", str5, delimiter5);
	result = ft_split(str5, delimiter5);
	if (!result[0])
		printf("Result: (No words found)\n");
	free(result);
	printf("\n");

	return (0);
} */