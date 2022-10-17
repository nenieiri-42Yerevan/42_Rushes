/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_unique.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:09:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/17 15:19:44 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	fix_unique_in_row(t_matrix *matrixes, int row, int val, int size)
{
	int	col;
	int	z;

	col = -1;
	while (++col < size)
	{
		z = -1;
		while (++z < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (matrixes->helper_matrix[row][col][z] == val)
			{
				matrixes->map_matrix[row][col] = val;
				free(matrixes->helper_matrix[row][col]);
				matrixes->helper_matrix[row][col] = 0;
				return ;
			}
		}
	}
}

static int	find_in_row(t_matrix *matrixes, int size)
{
	int	count;
	int	row;
	int	val;
	int	col;

	row = -1;
	while (++row < size)
	{
		val = -1;
		while (++val < size)
		{
			count = 0;
			col = -1;
			while (++col < size)
				if (matrixes->helper_matrix[row][col] != 0)
					count += if_in(matrixes->helper_matrix[row][col], val + 1, \
								size);
			if (count == 1)
			{
				fix_unique_in_row(matrixes, row, val + 1, size);
				return (1);
			}
		}
	}
	return (0);
}

static void	fix_unique_in_col(t_matrix *matrixes, int col, int val, int size)
{
	int	row;
	int	z;

	row = -1;
	while (++row < size)
	{
		z = -1;
		while (++z < size)
		{
			if (matrixes->helper_matrix[row][col] == 0)
				continue ;
			if (matrixes->helper_matrix[row][col][z] == val)
			{
				matrixes->map_matrix[row][col] = val;
				free(matrixes->helper_matrix[row][col]);
				matrixes->helper_matrix[row][col] = 0;
				return ;
			}
		}
	}
}

static int	find_in_col(t_matrix *matrixes, int size)
{
	int	count;
	int	row;
	int	val;
	int	col;

	col = -1;
	while (++col < size)
	{
		val = -1;
		while (++val < size)
		{
			count = 0;
			row = -1;
			while (++row < size)
				if (matrixes->helper_matrix[row][col] != 0)
					count += if_in(matrixes->helper_matrix[row][col], val + 1, \
								size);
			if (count == 1)
			{
				fix_unique_in_col(matrixes, col, val + 1, size);
				return (1);
			}
		}
	}
	return (0);
}

int	find_unique(t_matrix *matrixes, int size)
{
	int	count;

	count = 0;
	count += find_in_row(matrixes, size);
	if (count != 0)
		return (count);
	count += find_in_col(matrixes, size);
	if (count != 0)
		cross_clear(matrixes, size);
	return (count);
}
