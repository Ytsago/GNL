/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:29:45 by secros            #+#    #+#             */
/*   Updated: 2024/11/30 09:29:47 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
 # define BUFFER_SIZE 100
#endif

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct	s_read
{
	int				fd;
	t_list			*save;
	struct s_read	*next;
}	t_read;

char	*get_next_line(int fd);
int		new_line(t_list *lst);
void	*ft_lstclear(t_list **lst, void (*del)(void *));
void	*ft_lstaddnew_back(t_list **lst, void *content);
char	*lst_reboot(t_list *save);
void	lst_copy(t_list *lst, char *dst, size_t len);
size_t	lst_str_len(t_list *lst);

#endif