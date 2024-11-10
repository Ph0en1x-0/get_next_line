/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wimam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 18:10:46 by wimam             #+#    #+#             */
/*   Updated: 2024/11/10 17:43:51 by wimam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




int	ft_strlen(const char *s)
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







char	*ft_split(char *str, char ret)
{
	int		i;
	char	*buffer;

	buffer = ft_init(NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		buffer = ft_charjoin(buffer, str[i]);
		i++;
	}
	if(str[i] == '\n')
		buffer = ft_charjoin(buffer, '\n');
	if(ret == 'b')
		return (buffer);
	free(buffer);
	i++;
	return (&str[i]);
}








char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	int		i;
	int		j;

	if(*s1 == '\0')
		return(s2);
	else if (*s2 == '\0')
		return (s1);
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
	//free(s1);
	return (buffer);
}



