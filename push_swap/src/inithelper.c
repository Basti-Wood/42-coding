/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inithelper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sholz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:42:41 by sholz             #+#    #+#             */
/*   Updated: 2025/03/15 15:42:42 by sholz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift_elements(int array[], int j, int element)
{
	while (j >= 0 && array[j] > element)
	{
		array[j + 1] = array[j];
		j--;
	}
	array[j + 1] = element;
}

void	insertion_sort(int array[], int n)
{
	int	i;
	int	j;
	int	element;

	i = 1;
	j = 0;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		shift_elements(array, j, element);
		i++;
	}
}

int	correct_index(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}
