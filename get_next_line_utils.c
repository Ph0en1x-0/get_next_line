/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:46 by wimam             #+#    #+#             */
/*   Updated: 2024/11/12 22:15:54 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int 	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_init(char *s)
{
	if (!s)
	{
		char	*buffer;
		buffer = malloc(1);
		buffer[0] = '\0';
		return (buffer);
	}
	else
		return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_trim(char	*str, int max)
{
	char	*buffer;
	int		i;

	buffer = malloc(max + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < max)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	free(str);
	return (buffer);
}

int		is_fd_valid(int fd)
{
	if (fd < 0 || fcntl(fd, F_GETFL) == -1)
		return 0; // Not valid	
	return 1; // Valid
}
