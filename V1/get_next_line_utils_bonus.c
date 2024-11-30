/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:59:20 by secros            #+#    #+#             */
/*   Updated: 2024/11/29 11:02:10 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
				return(1);
			i++;
		}
		lst = lst->next;
	}
	return (0);
}

void	*ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pt;

	while (*lst)
	{
		pt = *lst;
		*lst = (*lst)->next;
		if(del && pt->content)
			del(pt->content);
		free(pt);
	}
	lst = NULL;
	return (NULL);
}
void	lst_copy(t_list *lst, char *dst, size_t len)
{
	size_t	i;
	char	*buff;

	i = 0;
	while(lst)
	{
		buff = lst->content; 
		while (i < len && *buff)
		{
			dst[i++] = *buff;
			buff++;
		}
		lst = lst->next;
	}
	dst[i] = '\0';
}

size_t	lst_str_len(t_list *lst)
{
	size_t	i;
	char	*str;

	i = 0;
	
	while(lst)
	{
		str = lst->content;
		while(*str)
		{
			str++;
			i++;
			if (*str == '\n')
				return (i + 1);
		}
		lst = lst->next;
	}
	return (i);
}

void	*ft_lstaddnew_back(t_list **lst, void *content)
{
	t_list	*pt;
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	if (!*lst)
		*lst = new;
	else
	{
		pt = *lst;
		while(pt->next)
			pt = pt->next;
		pt->next = new;
	}
	return (new);
}
