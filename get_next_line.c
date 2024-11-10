/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:11:05 by wimam             #+#    #+#             */
/*   Updated: 2024/11/10 17:25:58 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd)
{
	static	char	*later;
	char			*buffer;
	char			*tmp;
	
	later = ft_init(later);
	buffer = ft_init(NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	tmp[BUFFER_SIZE] = '\0';

	if (ft_new_line_check(later))
	{
		buffer = ft_split(later, 'b');
		later = ft_split(later, 'l');
		return (buffer);
	} else if (ft_strlen(later) > 0)
	{
		buffer = ft_strjoin(later, buffer);
	}
	
	while (read(fd, tmp, BUFFER_SIZE) > 0)
	{
		if(ft_new_line_check(tmp))
			break ;
		buffer = ft_strjoin(buffer, tmp);
	}

	if (ft_new_line_check(tmp))
	{
		buffer = ft_strjoin(buffer, ft_split(tmp, 'b'));
		later = ft_split(tmp, 'l');
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE == 0)
		return (NULL);
	return (get_line(fd));
}