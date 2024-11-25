/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:24:57 by secros            #+#    #+#             */
/*   Updated: 2024/11/25 17:38:44 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*create_node(t_list **save, char *buff, ssize_t readed)
{
	char	*str;

	str = malloc((1 + readed) * sizeof(char));
	if (!str)
		return (NULL);
	str[readed] = '\0';
	while (readed--)
		str[readed] = buff[readed];
	return(ft_lstadd_back(save, ft_lstnew(str)));
}

int	new_line(t_list *lst)
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
				return(0);
			i++;
		}
		lst = lst->next;
	}
	return (1);
}
char	*lst_copy(t_list *save)
{
	char	*sstr;
	char	*str;

	str = malloc(sizeof(char) * (1 + lst_str_len(save)));
	if (!str)
		return (NULL);
	while(save)
	{
		sstr = save->content; 
		while (*sstr && *str != '\n')
		{
			*str = *sstr;
			str++;
			sstr++;
		}
		save = save->content;
	}
	str = '\0';
	return (str);
}

char	*lst_reboot(t_list **save);
{

}

char	*get_next_line(int fd)
{
	static t_list	*save = NULL;
	char			buff[BUFFER_SIZE];
	ssize_t			readed;

	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	while (readed || new_line(save))
	{
		readed = read(fd, buff, BUFFER_SIZE);
		creat_node(&save, buff, readed);
	}
	lst_reboot(&save)
}

int main()
{
	char *save = "oui";
	char *buff = "Test 12\ntest 12";
	char *fs = NULL ;

	printf("%d\n%s\n%s\n", get_joined_line(&fs, &buff, &save));
}