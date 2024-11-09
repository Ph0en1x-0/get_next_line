/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:46 by wimam             #+#    #+#             */
/*   Updated: 2024/11/10 00:38:27 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
static	int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
static	char	*ft_charjoin(char *str, char c)
{
	char	*buffer;
	int		i;

	buffer = malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i] != '\0')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i++] = c;
	buffer[i] = '\0';
	free(str);
	return (buffer);
}

int		ft_new_line_check(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if(*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_split(char *str, char *ret)
{
	char	*buffer;
	int		i;
	
	buffer = malloc(1);
	buffer[0] = '\0';
	i = 0;
	while (*str && *str != '\n')
	{
		buffer = ft_charjoin(buffer, *str);
		str++;
		i++;
	}
	buffer[i] = '\n';
	if (ft_strcmp(ret, "now"))
		return (buffer);
	else
		free(buffer);
	return (str++);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;

	if(!s1)
		return(s2);
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while(*s1 != '\0')
	{
		buffer[i] = *s1;
		s1++;
		i++;
	}
	while(*s2 != '\0')
	{
		buffer[i] = *s2;
		s2++;
		i++;
	}
	free(s1);
	free(s2);
	buffer[i] = '\0';
	return (buffer);
}



