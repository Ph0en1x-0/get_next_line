/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:05 by wimam             #+#    #+#             */
/*   Updated: 2024/11/13 00:07:49 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_text(int fd)
{
	int	read_bytes;
	int total_read_bytes;
	char *buffer;
	char *tmp;

	read_bytes = 0;
	total_read_bytes = 0;
	tmp = malloc(BUFFER_SIZE);
	buffer = ft_init(NULL);
	while ((read_bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		total_read_bytes += read_bytes;
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	buffer = ft_trim(buffer, total_read_bytes);
	return (buffer);
}

char	*get_line(char	*text)
{
	int		len;
	int		i;
	char 	*line;

	len = 0;
	while(text[len] != '\n' && text[len] != '\0')
		len++;
	line = malloc(len + 2); // (\n + \0) = 2
	if (!line)
		return (line);
	i = 0;
	while (i <= len)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_text(char *text)
{
	char	*newtext;
	int		start;
	int		len;
	int		i;

	start = 0;
	
	while (text[start] != '\n')
	{
		if (text[start] == '\0') // for file with just line
		{
			free(text);
			return (NULL);
		}
		start++;
	}
	start++;
	len = ft_strlen(&text[start]);
	if (len == 0)
	{
		free(text);
		return (NULL);
	}
	newtext = malloc(len + 1);
	if (!newtext)
		return (NULL);
	i = 0;
	while(i < len)
	{
		newtext[i] = text[start + i];
		i++;	
	}
	newtext[len] = '\0';
	free(text);
	return (newtext);
}

char	*get_next_line(int fd)
{
	static	char	*text;
	char			*line;
	static	int		first_call;
	
	if (!is_fd_valid(fd))
		return (NULL);
	if (first_call == 0)
	{
		first_call = 1;
		text = get_text(fd);
	}
	if(!text)
		return(NULL);
	line = get_line(text);
	text = update_text(text);
	return (line);
}