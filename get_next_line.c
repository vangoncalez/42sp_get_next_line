/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 10:45:49 by vaferrei          #+#    #+#             */
/*   Updated: 2021/09/15 22:23:03 by vaferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_backup(int fd, char *backup)
{
	char	*buffer;
	int		readbuffer;
	int		control;
	char	*temp;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readbuffer = 1;
	control = 0;
	while (control == 0 && readbuffer != 0)
	{
		if (ft_strchr(backup, '\n'))
			control = 1;
		readbuffer = read(fd, buffer, BUFFER_SIZE);
		if (readbuffer == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbuffer] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		free (temp);
	}
	free(buffer);
	return (backup);
}

char	*make_line(char *backup)
{
	size_t		i;
	char		*line;

	i = 0;
	while (*backup)
	{
		if (backup[i] == '\n')
			break;
		i++;
	}
	if (!backup[i])
		return (NULL);
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	ft_strlcpy(line, backup, i + 2);

	return (line);
}

char	*make_newbackup(char *backup)
{
	int		i;
	char	*newbackup;

	i = 0;
	while (*backup)
	{
		if (backup[i] == '\n')
			break;
		i++;
	}
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	newbackup = ft_substr(backup, i + 1, ft_strlen(backup) - i);
	free(backup);
	return (newbackup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	backup = make_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = make_line(backup);
	if (!line)
		return (NULL);
	backup = make_newbackup(backup);
	return (line);
}
