/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:10:42 by lumfred           #+#    #+#             */
/*   Updated: 2021/10/20 11:31:27 by lumfred          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	*split_mem_free(char **res, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(res[j]);
		j++;
	}
	free(*res);
	return (NULL);
}

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[0] != '\0')
	{
		while (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			count++;
			while (s[i] == c && s[i] != '\0')
				i++;
		}
		if (s[0] == c)
			count--;
	}
	return (count);
}

static char	*next_word(const char *s, int i, char c)
{
	char			*word;
	unsigned int	j;
	size_t			len;
	int				k;
	int				index;

	k = 0;
	j = 0;
	while (k <= i)
	{
		len = 0;
		while (s[j] == c)
			j++;
		index = j;
		while (s[j] != c && s[j] != '\0')
		{
			len++;
			j++;
		}
		if (k == i)
			word = ft_substr(s, (unsigned int)index, len);
		k++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	if (s == NULL)
		return ((char **) NULL);
	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	res[count_words(s, c)] = NULL;
	i = 0;
	while (i < count_words(s, c))
	{
		res[i] = next_word(s, i, c);
		if (res[i] == NULL)
			return (split_mem_free(res, i));
		i++;
	}
	return (res);
}
