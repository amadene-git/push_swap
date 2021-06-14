/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:51:57 by admadene          #+#    #+#             */
/*   Updated: 2021/06/09 14:45:20 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*ft_chr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (!*s && !c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len;
	char	*cpy;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	cpy = s1;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(cpy);
	return (str - len);
}

char	*ft_sub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (start >= ft_strlen((char *)s))
	{
		*str = '\0';
		return (str);
	}
	s += start;
	while (i++ < len && *s)
		*str++ = *s++;
	*str = '\0';
	return (str - i + 1);
}

int	get_current_line(int fd, char **save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret && !ft_chr(*save, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			buffer[ret] = 0;
			*save = ft_strjoin(*save, buffer);
			if (!*save)
				return (0);
		}
	}
	if (!*save)
		*save = ft_strdup("");
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[1024];
	char		*tmp;

	if (read(fd, NULL, 0) == -1 || !line || BUFFER_SIZE < 1 || \
	!get_current_line(fd, &save[fd]))
		return (-1);
	tmp = save[fd];
	if (ft_chr(save[fd], '\n'))
	{
		*line = ft_sub(save[fd], 0, (ft_chr(save[fd], '\n') - save[fd]));
		if (!*line)
			return (-1);
		save[fd] = ft_strdup(ft_chr(save[fd], '\n') + 1);
		if (fd == 0)
		{
			free(save[fd]);
			save[fd] = NULL;
		}
		free(tmp);
		tmp = NULL;
		return (1);
	}
	*line = ft_strdup(save[fd]);
	free(tmp);
	save[fd] = NULL;
	return (0);
}
