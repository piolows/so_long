/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:03:26 by ppolinta          #+#    #+#             */
/*   Updated: 2024/01/26 19:03:26 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	wordcount(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			count++;
		}
		if (*s == '\0')
			break ;
		s++;
	}
	return (count);
}

static char	*getword(const char *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char	**split_sl(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	split = malloc(sizeof(char *) * (wordcount(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] && j < wordcount(s, c))
	{
		if (s[i] == c && s[i])
			i++;
		split[j] = getword(s + i, c);
		i += ft_strlen(split[j]);
		j++;
	}
	split[j] = NULL;
	return (split);
}
