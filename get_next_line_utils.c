/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:46 by wimam             #+#    #+#             */
/*   Updated: 2024/11/09 18:20:14 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	unsigned char *buffer;

	buffer = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		buffer[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;
	
	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_join(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if(!s2)
		return (s1);
	if (!s1)
	{
		s1 = malloc(1);
		*s1 = '\0';
	}
	buffer = malloc(BUFFER_SIZE + ft_strlen(s1) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while(s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		buffer[i + j] = s2[j];
		j++;
	}
	buffer[i + j] = '\0';
	free(s1); 
	return (buffer);
}

int		eol(char *str) //end of line
{
	int	i;

	i = 0;
	while (str[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if(i == BUFFER_SIZE)
		return (1);
	return (0);
}

char	*get_later(char *str) // Returns the pointer after the newline
{
	while (*str != '\n' && *str != '\0')
		str++;
	if (*str == '\n')
		str++;
	return (str);
}
