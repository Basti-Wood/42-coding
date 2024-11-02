/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:43:20 by sholz             #+#    #+#             */
/*   Updated: 2024/10/30 17:43:21 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*strsub;
	unsigned int	i;

	res = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!s || !res)
	{
		return (NULL);
	}
	while (s[start + i] && i <= len)
	{
		res[i] = s[i + start];
		i += 1;
	}
	res[i] = '\0';
	return (res);
}
