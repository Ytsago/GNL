/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:24:53 by secros            #+#    #+#             */
/*   Updated: 2024/11/25 17:32:32 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 10
#endif

/* typedef struct	s_read
{
	int				fd;
	t_list			*save;
	struct s_line	*next;
}	t_read;
 */
typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	ft_lstclear(t_list **lst, void (*del)(void *));
void	*ft_lstadd_back(t_list **lst, t_list *new);
size_t	lst_str_len(t_list *lst);
t_list	*ft_lstnew(void *content);

#endif