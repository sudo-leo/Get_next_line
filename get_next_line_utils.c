/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmelli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 16:05:36 by larmelli          #+#    #+#             */
/*   Updated: 2021/02/05 16:05:41 by larmelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		len(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	else
	{
		while (s[i] != '\0')
			i++;
		return (i);
	}
}

int		nl_check(char *saved)
{
	int i;

	i = 0;
	while (saved[i])
	{
		if (saved[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		len1;
	int		len2;
	char	*str;

	if (s1 && s2)
	{
		len1 = len(s1);
		len2 = len(s2);
		if (!(str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = 0;
		while (s2[i])
		{
			str[len1] = s2[i++];
			len1++;
		}
		str[len1] = '\0';
		free(s1);
		return (str);
	}
	return (NULL);
}

char	*until_nl(char *str, char c)
{
	int		i;
	int		j;
	char	*risultato;

	i = 0;
	j = 0;
	while (str[j] != c)
		j++;
	if (!(risultato = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (str[i] != c)
	{
		risultato[i] = str[i];
		i++;
	}
	risultato[i] = '\0';
	return (risultato);
}

char	*after_nl(char *str)
{
	char	*dest;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!str)
		return (0);
	while (str[x] && str[x] != '\n')
		x++;
	if (!(dest = (char *)malloc(sizeof(char) * ((len(str) - x) + 1))))
		return (0);
	if (str[x] == 10)
		x++;
	while (str[x])
		dest[y++] = str[x++];
	dest[y] = '\0';
	free(str);
	return (dest);
}
