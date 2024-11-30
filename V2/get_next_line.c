/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:46:03 by secros            #+#    #+#             */
/*   Updated: 2024/11/30 16:53:50 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	fs = ft_strfreejoin(str, end);
	free(end);
	buff_cleaner(buff, i);
	if (!fs)
		return (NULL);
	return (fs);
}

char	*read_file(int fd, char *buff)
{
	ssize_t		size;
	char		*str;

	str = NULL;
	size = 1;
	while (size > 0 && !is_new_line(buff))
	{
		str = ft_strfreejoin(str, buff);
		if (!str)
			return (NULL);
		if (size < 0 && str)
			free(str);
		if (size < 0)
			return (NULL);
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = '\0';
	}
	if (size > 0)
		str = build_line(str, buff);
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

/* int main ()
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
} */