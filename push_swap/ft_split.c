/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdangwal <pdangwal@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 17:49:08 by pdangwal          #+#    #+#             */
/*   Updated: 2025/07/08 16:27:43 by pdangwal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_givespace(char const *b, int start, int end)
{
	char	*dest;
	int		len;
	int		i;

	len = end - start;
	dest = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = b[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_numstrings(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	ft_free_all(char **dest, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

static int	ft_split2(char const *s, char **dest, char c)
{
	int	i;
	int	k;
	int	start;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		dest[k] = ft_givespace(s, start, i);
		if (!dest[k])
		{
			ft_free_all(dest, k);
			return (0);
		}
		k++;
	}
	dest[k] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_numstrings(s, c) + 1));
	if (!dest)
		return (NULL);
	if (!ft_split2(s, dest, c))
		return (NULL);
	return (dest);
}
/*
int	main(void)
{
	const char	*str = "hello!";
	const char	delim = ' ';
	char		**result;
	int			i;

	result = ft_split(str, delim);
	if (!result)
	{
		printf("Memory allocation failed!\n");
		return (1);
	}
	i = 0;
	while (result[i])
	{
		printf("Substring %d: '%s'\n", i + 1, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}
//*/
