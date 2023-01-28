/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:53:23 by rchbouki          #+#    #+#             */
/*   Updated: 2023/01/27 17:49:37 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_bonus(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_bonus(char *s, int c)
{
	char	l;
	char	e;

	l = (char)(c);
	while (*s)
	{
		e = *s;
		if (e == l)
			return (s + 1);
		s++;
	}
	return (NULL);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	str = malloc(ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strdup_bonus(char *s, int test)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (ft_strlen_bonus(s) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	dup[i] = '\0';
	if (test == 1)
		free(s);
	return (dup);
}

char	*ft_substr_bonus(char *s)
{
	char	*new;
	int		i;
	int		start;

	i = 0;
	start = 0;
	while (s[start] != '\n')
		start++;
	start += 1;
	if (!s[start + i])
		return (free(s), NULL);
	new = malloc(sizeof(char) * (ft_strlen_bonus(s) - start + 1));
	if (!new)
		return (NULL);
	while ((s[start + i]))
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	free(s);
	return (new);
}
