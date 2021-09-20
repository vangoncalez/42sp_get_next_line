/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:45:49 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/20 07:59:09 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*make_backup(int fd, char *backup, char	*buffer)
{
	int		readbuffer;
	int		control;
	char	*temp;

	readbuffer = 1;
	control = 0;
	while (control == 0 && readbuffer != 0)
	{
		readbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readbuffer == -1 )
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbuffer] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(backup, '\n'))
			control = 1;
	}
	free(buffer);
	return (backup);
}

char	*make_line(char *backup)
{
	int			i;
	char		*line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *) malloc (sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, i + 2);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*make_newbackup(char *backup)
{
	int			i;
	char		*newbackup;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	newbackup = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!newbackup)
		return (NULL);
	ft_strlcpy(newbackup, backup + i + 1, ft_strlen(backup) - i + 1);
	free(backup);
	return (newbackup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup[OPEN_MAX];
	char		*buffer;

	line = NULL;
	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	backup[fd] = make_backup(fd, backup[fd], buffer);
	if (!backup[fd])
		return (NULL);
	line = make_line(backup[fd]);
	backup[fd] = make_newbackup(backup[fd]);
	return (line);
}
