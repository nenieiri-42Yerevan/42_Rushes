/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:18:20 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/14 18:34:30 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	row_cleaner(int **helper_matrix, int val, int size)
{
	int	count;
	int	col;
	int	z;

	count = 0;
	col = -1;
	while (++col < size)
	{
		if (helper_matrix[col] == 0)
			continue ;
		z = -1;
		while (++z < size)
		{
			if (helper_matrix[col][z] == val)
			{
				helper_matrix[col][z] = -10;
				++count;
			}
		}
	}
	return (count);
}

static int	col_cleaner(int ***helper_matrix, int col, int val, int size)
{
	int	count;
	int	row;
	int	z;

	count = 0;
	row = -1;
	while (++row < size)
	{
		if (helper_matrix[row][col] == 0)
			continue ;
		z = -1;
		while (++z < size)
		{
			if (helper_matrix[row][col][z] == val)
			{
				helper_matrix[row][col][z] = -10;
				++count;
			}
		}
	}
	return (count);
}

int	cross_clear(t_matrix *matrixes, int size)
{
	int	row;
	int	col;
	int	count;

	row = -1;
	count = 0;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
			{
				count += row_cleaner(matrixes->helper_matrix[row], \
										matrixes->map_matrix[row][col], size);
				count += col_cleaner(matrixes->helper_matrix, col, \
										matrixes->map_matrix[row][col], size);
			}
		}
	}
	return (count);
}
