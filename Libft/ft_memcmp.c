/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:27:37 by sholz             #+#    #+#             */
/*   Updated: 2024/10/28 12:27:38 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t	i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = (char *)ptr1;
	str2 = (char *)ptr2;
	while (i <= num && str1[i] == str2[i])
	{
		i++;
	}
	if (i == num)
	{
		return (0);
	}
	else
	{
		return (str1[i] - str2[i]);
	}
}
/*

#include <stdio.h>
#include <string.h>

int main() {
    char buffer1[] = "ABC";
    char buffer2[] = "ABD";

    int result = memcmp(buffer1, buffer2, 3);

    if (result < 0) {
        printf("buffer1 is less than buffer2\n");
    } else if (result > 0) {
        printf("buffer1 is greater than buffer2\n");
    } else {
        printf("buffer1 is equal to buffer2\n");
    }

    return 0;
}
*/
