/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:46 by wimam             #+#    #+#             */
/*   Updated: 2024/11/11 14:28:08 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if(!s1)
		return(s2);
	else if(!s1 || !s2)
		return (NULL);
	buffer = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
    {
        buffer[i] = s1[i];
        i++;
    }
    while (s2 && s2[j] != '\0')
    {
        buffer[i] = s2[j];
        i++;
        j++;
    }
	buffer[i] = '\0';
	free(s1);
	return (buffer);
}

char	*ft_charjoin(char *str, char c)
{
	char	*buffer;
	int		i;

	buffer = malloc(ft_strlen(str) + 2);
	if (!buffer)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i++] = c;
	buffer[i] = '\0';
	//free(str);
	return (buffer);
}

char	*ft_trim(char *str, int len)
{
	char	*buffer;
	int		i;
	
	buffer = ft_init(buffer);
	i = 0;
	while(i < len)
	{
		buffer = ft_charjoin(buffer, str[i]);
		i++;
	}
	free(str);
	return (buffer = ft_charjoin(buffer, '\0'));
}