/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchbouki <rchbouki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:19:35 by rchbouki          #+#    #+#             */
/*   Updated: 2023/01/27 18:04:40 by rchbouki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_last_bonus(char *temp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (temp[i] != '\n' && temp[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (temp[i] != '\n' && temp[i])
		str[j++] = temp[i++];
	if (temp[i] == '\n')
		str[j] = '\n';
	str[j + 1] = '\0';
	return (str);
}

char	*ft_read_buff_bonus(int fd)
{
	char	*temp;
	int		res;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	res = read(fd, temp, BUFFER_SIZE);
	temp[res] = '\0';
	if (res == 0)
		return (free(temp), NULL);
	return (temp);
}

char	*ft_read_line_bonus(int fd, char *stat)
{
	char	*temp;
	char	*final;
	char	*last;

	temp = ft_read_buff_bonus(fd);
	if (!temp && !stat)
		return (free(temp), temp = NULL);
	if (!stat)
		final = ft_strdup_bonus("", 0);
	else
		final = ft_strdup_bonus(stat, 0);
	while (temp && !ft_strchr_bonus(temp, '\n'))
	{
		last = ft_strdup_bonus(final, 1);
		final = ft_strjoin_bonus(last, temp);
		free(temp);
		temp = ft_read_buff_bonus(fd);
	}
	if (temp)
	{
		last = ft_strdup_bonus(final, 1);
		final = ft_strjoin_bonus(last, temp);
	}
	return (free(temp), final);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*temp;
	char		*result;

	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(str[fd]), str[fd] = NULL);
	if (str[fd] && ft_strchr_bonus(str[fd], '\n'))
	{
		temp = ft_get_last_bonus(str[fd]);
		result = ft_strdup_bonus(str[fd], 1);
		str[fd] = ft_substr_bonus(result);
		return (temp);
	}
	temp = ft_read_line_bonus(fd, str[fd]);
	if (!temp)
		return (free(str[fd]), str[fd] = NULL);
	if (ft_strchr_bonus(temp, '\n'))
	{
		result = ft_get_last_bonus(temp);
		free(str[fd]);
		str[fd] = ft_substr_bonus(temp);
		return (result);
	}
	return (free(str[fd]), str[fd] = NULL, temp);
}
