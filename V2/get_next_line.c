/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:46:03 by secros            #+#    #+#             */
/*   Updated: 2024/11/30 14:58:19 by secros           ###   ########.fr       */
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

void	buff_cleaner(char *buff, size_t i)
{
	size_t	j;
	
	j = 0;
	while (buff[i])
		buff[j++] = buff[i++];
	while (buff[j])
		buff[j++] = '\0';
}

char	*build_line(char *str, char *buff)
{
	char	*end;
	char	*fs;
	size_t	i;

	i = 0;
	end = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!end)
		return (NULL);
	while (buff[i] && buff[i] != '\n')
	{
		end[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
		end[i++] = '\n';
	end[i] = '\0';
	fs = ft_strjoin(str, end);
	free(end);
	buff_cleaner(buff, i);
	if (!fs)
		return (NULL);
	return (fs);
}

char	*read_file(int fd, char *buff)
{
	ssize_t		size;
	size_t		i;
	char		*str;

	str = NULL;
	size = 1;
	i = 0;
	while (size > 0 && !is_new_line(buff))
	{
		str = ft_strjoin(str, buff);
		if (!str)
			return (NULL);
		if (size < 0 && str)
			free(str);
		if (size < 0)
			return (NULL);
		size = read(fd, buff, BUFFER_SIZE);
	}
	if (size > 0)
		str = build_line(str, buff);
	else
		while (i < BUFFER_SIZE)
			buff[i++] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_file(fd, buff);
	if (!str)
		return (NULL);
	if (!*str)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

int main ()
{
	int fd = open("test.txt", O_RDONLY);
	int	i = 0;
	char *str = "0123456789012345678901234567890123456789012";

	str = get_next_line(fd);
	while(str)
	{
		printf("Ligne %d: %s", i, str);
		free(str);
		str = get_next_line(fd);
		i++;
	}
}