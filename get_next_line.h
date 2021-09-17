/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:45:49 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/16 23:04:36 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*make_backup(int fd, char *backup, char	*buffer);
char	*make_line(char *backup);
char	*make_newbackup(char *backup);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(const char *str);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strdup(char *string);

#endif
