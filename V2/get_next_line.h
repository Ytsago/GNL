/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:29:40 by secros            #+#    #+#             */
/*   Updated: 2024/11/30 16:52:14 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
 #  define BUFFER_SIZE 42
# endif

void	buff_cleaner(char *buff, size_t i);
int	is_new_line(char *str);
char	*ft_strfreejoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif