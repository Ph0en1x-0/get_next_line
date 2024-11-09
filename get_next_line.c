/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:05 by wimam             #+#    #+#             */
/*   Updated: 2024/11/10 00:38:15 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	static	char	*later;
	char			*buffer;
	char			*tmp;
	
	buffer = malloc(1);
	buffer[0] = 0;
	if (ft_new_line_check(later))
	{
		buffer = ft_split(later, "now");
		later = ft_split(later, "later");
		return(buffer);
	}
	tmp = malloc(BUFFER_SIZE + 1);
	while (ft_new_line_check(later) && read(fd, tmp, BUFFER_SIZE) > 0)
		buffer = ft_strjoin(buffer, tmp);
	buffer = ft_strjoin(buffer, ft_split(tmp, "now"));
	later = ft_split(tmp, later);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = get_line(fd);
	
	return (line);
}