/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:05 by wimam             #+#    #+#             */
/*   Updated: 2024/11/09 18:19:35 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(fd)
{
	char	*tmp;
	char	*buffer;
	char	static	*later;

	tmp = malloc(BUFFER_SIZE + 1);
	buffer = malloc(1);
	
	ft_memset(buffer, '\0', 1);
	while (TRUE)
	{
		read(fd, tmp, BUFFER_SIZE);
		tmp[BUFFER_SIZE + 1] = '\0';
		if (eol(tmp))
			break ;
		buffer = ft_join(buffer, tmp);
	}
	buffer = ft_join(later, buffer);
	buffer = ft_join(buffer, "\n");
	later = get_later(tmp);
	return(buffer);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = get_line(fd);
	
	return (line);
}