/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:18:20 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/14 14:15:33 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	row_cleaner(int **helper_matrix, int val, int size)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (helper_matrix[i] == 0)
				continue ;
			if (helper_matrix[i][j] == val)
			{
				helper_matrix[i][j] = -10;
				++count;
			}
		}
	}
	return (count);
}

static int	col_cleaner(int ***helper_matrix, int col, int val, int size)
{
	int	count;
	int	i;
	int	z;

	count = 0;
	i = -1;
	while (++i < size)
	{
		z = -1;
		while (++z < size)
		{
			if (helper_matrix[i][col] == 0)
				continue ;
			if (helper_matrix[i][col][z] == val)
			{
				helper_matrix[i][col][z] = -10;
				++count;
			}
		}
	}
	return (count);
}

int	cross_clear(t_matrix *matrixes, int size)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	count = 0;
	while (matrixes->helper_matrix[++i] != 0)
	{
		j = -1;
		while (++j < size)
		{
			if (matrixes->helper_matrix[i][j] == 0)
			{
				count += row_cleaner(matrixes->helper_matrix[i], \
										matrixes->map_matrix[i][j], size);
				count += col_cleaner(matrixes->helper_matrix, j, \
										matrixes->map_matrix[i][j], size);
			}
		}
	}
	return (count);
}
