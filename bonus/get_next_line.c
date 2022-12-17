/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: otait-ta <otait-ta@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/11/03 20:13:44 by otait-ta          #+#    #+#             */
/*   Updated: 2022/11/03 20:13:44 by otait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (0);
	}
	str = find_new_line(fd, str);
	if (!str)
		return (NULL);
	line = get_new_line(str);
	str = find_rest(str);
	return (line);
}

char	*find_new_line(int fd, char *line)
{
	char	*buff;
	int		rtr;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rtr = 69;
	while (rtr != 0 && !ft_strchr(line, '\n'))
	{
		rtr = read(fd, buff, BUFFER_SIZE);
		if (rtr < 0)
			return (free(line), free(buff), NULL);
		buff[rtr] = '\0';
		line = ft_gnl_strjoin(line, buff);
	}
	return (free(buff), line);
}

char	*get_new_line(char *old)
{
	int		i;
	char	*line;

	i = 0;
	if (!*old)
		return (NULL);
	while (old[i] && old[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (old[++i] && old[i] != '\n')
		line[i] = old[i];
	if (old[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*find_rest(char *str)
{
	char	*rest;
	int		i;
	int		j;
	size_t	rest_size;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	rest_size = ft_gnl_strlen(str) - i + 1;
	rest = (char *)malloc(sizeof(char) * rest_size);
	if (!rest)
		return (NULL);
	i++;
	while (str[i])
		rest[j++] = str[i++];
	rest[j] = '\0';
	return (free(str), rest);
}
