/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:50:28 by sholz             #+#    #+#             */
/*   Updated: 2025/04/01 17:50:29 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	*read_first_line(int fd, char **current_line)
{
	char	*full_map;

	full_map = ft_strdup("");
	if (!full_map)
	{
		ft_error("Memory allocation failed", 1);
		return (NULL);
	}
	*current_line = get_next_line(fd);
	return (full_map);
}

static char	*process_remaining_lines(int fd, char *full_map, char *current_line)
{
	char	*temp;

	while (current_line != NULL)
	{
		temp = full_map;
		full_map = ft_strjoin(temp, current_line);
		free(temp);
		free(current_line);
		if (!full_map)
		{
			ft_error("Memory allocation failed", 1);
			return (NULL);
		}
		current_line = get_next_line(fd);
	}
	return (full_map);
}

char	*get_map(int fd)
{
	char	*current_line;
	char	*full_map;

	full_map = read_first_line(fd, &current_line);
	if (!full_map)
		return (NULL);
	full_map = process_remaining_lines(fd, full_map, current_line);
	if (!full_map)
		return (NULL);
	if (ft_strlen(full_map) == 0)
	{
		free(full_map);
		ft_error("Map is empty", 1);
		return (NULL);
	}
	return (full_map);
}
