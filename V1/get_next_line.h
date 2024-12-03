/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:24:53 by secros            #+#    #+#             */
/*   Updated: 2024/12/02 10:00:26 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 42
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

char	*get_next_line(int fd);
int		new_line(t_list *lst);
void	*ft_lstclear(t_list **lst, void (*del)(void *));
void	*ft_lstaddnew_back(t_list **lst, void *content);
char	*lst_reboot(t_list *save);
void	lst_copy(t_list *lst, char *dst, size_t len);
size_t	lst_str_len(t_list *lst);

#endif