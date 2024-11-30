/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:29:31 by secros            #+#    #+#             */
/*   Updated: 2024/11/30 13:24:27 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_new_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*fs;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s1)
		while (s1[len1])
			len1++;
	while (s2[len2])
		len2++;
	fs = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!fs && s1)
		free(s1);
	if (!fs)
		return (NULL);
	fs[len1 + len2] = '\0';
	while ((len2-- > 0))
		fs[len1 + len2] = s2[len2];
	while (len1-- > 0)
		fs[len1] = s1[len1];
	if (s1)
		free(s1);
	return (fs);
}

char	*build_line(char *str, char *buff)
{
	char	end[BUFFER_SIZE + 1];
	char	*fs;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
	{
		end[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		end[i++] = '\n';
	end[i] = '\0';
	fs = ft_strjoin(str, end);
	if (!fs)
		return (NULL);
	while (buff[i])
		buff[j++] = buff[i++];
	while (buff[j])
		buff[j++] = '\0';
	return (fs);
}
int	read_file(int fd, char *buff, char **str)
{
	ssize_t		size;
	
	size = 1;
	while (size > 0 && !is_new_line(buff))
	{
		*str = ft_strjoin(*str, buff);
		if (!*str)
			return (-1);
		if (size < 0 && *str)
			free(*str);
		if (size < 0)
			return (-1);
		size = read(fd, buff, BUFFER_SIZE);
	}
	return (size);
}
char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;
	int			end;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	end = read_file(fd, buff, &str);
	if (end == -1)
		return (NULL);
	if (end > 0)
		str = build_line(str, buff);
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return(NULL);
	}
	return (str);
}

/* int main ()
{
	int fd = open("1", O_RDONLY);
	int	i = 0;
	char *str = NULL;

	str = get_next_line(fd);
	while(str)
	{
		printf("Ligne %d: %s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
}
 */