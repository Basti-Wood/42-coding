#include "get_next_line.h"
/*DU MUSST DAS HIER NOCH ÄNDERN!!!!!
NICHT KOPIEREN!!!!!!!!!!*/

static char	*temp_keep_rest(char *temp, int start)
{
	char	*rest;
	int		len;

	len = ft_strlen(temp) - start;
	if (len <= 0)
	{
		free(temp);
		return (NULL);
	}
	rest = ft_substr(temp, start, len);
	free(temp);
	return (rest);
}

static char	*temp_extract_line(char *temp, int *start_next)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		*start_next = i + 1;
	else
	{
		*start_next = i;
		if (i == 0 && temp[i] == '\0')
			return (NULL);
	}
	line = ft_substr(temp, 0, *start_next);
	return (line);
}

static char	*temp_new_line(int fd, char *buffer, char *temp)
{
	int		read_bytes;
	char	*new_temp;

	while (!ft_strchr(temp, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == 0 && temp[0] == '\0')
		{
			free(temp);
			return (NULL);
		}
		if (read_bytes <= 0)
			return (temp);
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin(temp, buffer);
		free(temp);
		temp = new_temp;
	}
	return (temp);
}

char	*temp_get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*temp;
	int			start_next;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (temp == NULL)
		temp = ft_strdup("");
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp = temp_new_line(fd, buffer, temp);
	free(buffer);
	if (!temp)
		return (NULL);
	line = temp_extract_line(temp, &start_next);
	if (!line && !temp)
		return (NULL);
	temp = temp_keep_rest(temp, start_next);
	return (line);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

//eigene imlementierung

