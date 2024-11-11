/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:05 by wimam             #+#    #+#             */
/*   Updated: 2024/11/11 14:37:20 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_text(int fd)
{
	char	*tmp;
	char	*buffer;
	int		read_bytes;
	int		total;
	
	tmp = malloc(BUFFER_SIZE + 1);
	buffer = ft_init(NULL);
	read_bytes = 0;
	total = 0;
	while((read_bytes = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		total += read_bytes;
		tmp[BUFFER_SIZE] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	buffer = ft_trim(buffer, total);
	return(buffer);
}

int		ft_linenumbers(char	*text)
{
	int	num;

	num = 0;
	while(*text)
	{
		if (*text == '\n')
			num++;
		text++;
	}
	return (num);
}

char	*ft_get_line(char	*text, char ret)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = ft_init(NULL);
	while(text[i] != '\0' && text[i] != '\n')
	{
		buffer = ft_charjoin(buffer, text[i]);
		i++;
	}
	if(ret == 'L')
		return (buffer = ft_charjoin(buffer, '\n'));
	else if (ret == 'T')
	{
		free(buffer);
		return (&text[i + 1]);
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static	int		open;
	static	int		maxline;
	static	int		linei;
	static	char	*text;
	char			*line;
	
	if(open == 0)
	{
		text = get_text(fd);
		open = 1;
		maxline = ft_linenumbers(text);
	}
	if(linei - 1 == maxline)
		return (NULL);
	line = ft_get_line(text, 'L');
	text = ft_get_line(text, 'T');
	linei++;
	return (line);
}