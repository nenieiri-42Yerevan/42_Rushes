/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_random.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:23:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 13:55:02 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	if_end(t_matrix *matrixes, int size)
{
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
			if (matrixes->helper_matrix[row][col] != 0)
				return (-1);
	}
	return (0);
}

static int	count_size(int *helper_matrix, int size)
{
	int	count;
	int	j;

	count = 0;
	j = -1;
	while (++j < size)
	{
		if (helper_matrix[j] != -10)
			++count;
	}
	return (count);
}

static int	*find_cell(t_matrix *matrixes, int size, int count)
{
	int	row;
	int	col;

	row = -1;
	while (matrixes->helper_matrix[row] != 0)
	{
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (count_size(matrixes->helper_matrix[row][col], size) == count)
				return (matrixes->map_matrix[row][col]);
		}
	}
	return (0);
}

int	*find_min_random(t_matrix *matrixes, int size)
{
	int	count;
	int	row;
	int	col;

	count = 10;
	if (if_end(matrixes, size) == -1)
		return (0);
	row = -1;
	while (matrixes->helper_matrix[row] != 0)
	{
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (count_size(matrixes->helper_matrix[row][col], size) < count)
				count = count_size(matrixes->helper_matrix[row][col], size);
		}
	}
	return (find_cell(matrixes, size, count));
}
