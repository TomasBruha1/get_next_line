/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42Prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:07:32 by tbruha            #+#    #+#             */
/*   Updated: 2024/08/17 16:07:33 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// BUFFER_SIZE & MAX_FD

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define MAX_FD 1024

// HEADERS

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// MAIN FUNCTIONS

char	*get_next_line(int fd);
char	*read_content(int fd, char *r);
char	*prep_current_line(char *read);
char	*get_rest(char *read);

// UTILITY FUNCTIONS

char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

#endif
