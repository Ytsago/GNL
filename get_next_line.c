/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:24:57 by secros            #+#    #+#             */
/*   Updated: 2024/11/27 17:29:00 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	new_line(t_list *lst)
{
	size_t	i;
	char	*str;

	while(lst)
	{
		i = 0;
		str = lst->content;
		while(str[i])
		{
			if(str[i] == '\n')
				return(1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

int	create_node(t_list **save, int fd)
{
	char	*str;
	ssize_t	readed;

	readed = 1;
	while (!new_line(*save) && readed > 0)
	{
		str = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!str)
			return (0);
		readed = read(fd, str, BUFFER_SIZE);
		if (readed > 0)
			str[readed] = '\0';
		if(readed < 0 || !ft_lstaddnew_back(save, str))
		{
			ft_lstclear(save, free);
			return (0);
		}
	}
	return (1);
}

char	*lst_to_str(t_list **save)
{
	char	*str;
	char	*remain;
	size_t	len;
	t_list	*temp;

	len = lst_str_len(*save);
	str = malloc(sizeof(char) * (len + 1));
	if(!str)
	{
		ft_lstclear(save, free);
		return (NULL);
	}
	lst_copy(*save, str, len);
	temp = *save;
	while(temp->next)
		temp = temp->next;
	remain = lst_reboot(temp);
	ft_lstclear(save, free);
	if(!ft_lstaddnew_back(save, remain))
	{
		if (remain)
			free(remain);
		free(str);
	}
	return (str);
}

char	*lst_reboot(t_list *save)
{
	char	*buff;
	char	*str;
	size_t	len;

	len = 0;
	buff = save->content;
	while(*buff != '\n' && *buff)
		buff++;
	if (*buff == '\n')
		buff++;
	while(buff[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if(!str)
		return (NULL);
	len = 0;
	while (*buff)
		str[len++] = *buff++;
	str[len] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!create_node(&save, fd))
		return (NULL);
	str = (lst_to_str(&save));
	if (str[0] == '\0')
	{
		free(str);
		ft_lstclear(&save, free);
		return(NULL);
	}
	return (str);
}

int main()
{
	char	*str;
	char	*start = "Starting\n";
	int		i = 0;
	int		fd = open("test.txt", O_RDONLY);

	str = start;
	while(str && i <15)
	{
		printf("Ligne %d: %s", i, str);
		str = get_next_line(fd);
		i++;
	}
}