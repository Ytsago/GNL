/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:25:01 by secros            #+#    #+#             */
/*   Updated: 2024/11/25 17:49:24 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pt;

	while (*lst)
	{
		pt = *lst;
		*lst = (*lst)->next;
		if(del)
			del(pt->content);
		free(pt);
	}
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
		}
		lst = lst->next;
	}
	return (i);
}

void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pt;

	if (!new)
		return(NULL);
	if (!*lst)
		*lst = new;
	else
	{
		pt = *lst;
		while(pt->next)
			pt = pt->next;
		pt->next = new;
	}
	return(new);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int main()
{
	char *str;
	str = test();
	printf("%s", str);
}