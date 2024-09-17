/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:07:39 by tbruha            #+#    #+#             */
/*   Updated: 2024/08/17 16:07:40 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	cc;

	if (!s)
		return (NULL);
	i = 0;
	cc = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc(len + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (len > 0)
	{
		str[i] = s[i + start];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjnd;
	size_t	s1len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	strjnd = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjnd)
		return (NULL);
	s1len = ft_strlen(s1);
	i = 0;
	while (s1 != NULL && s1[i])
	{
		strjnd[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[i - s1len])
	{
		strjnd[i] = s2[i - s1len];
		i++;
	}
	strjnd[i] = '\0';
	free(s1);
	return (strjnd);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}
