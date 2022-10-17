/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_only.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:46:36 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/17 15:22:41 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	count_values(int *str, int size)
{
	int	count;
	int	z;

	count = 0;
	z = -1;
	while (++z < size)
	{
		if (str[z] != -10)
			++count;
	}
	return (count);
}

static void	fix_unique_val(t_matrix *matrixes, int row, int col, int size)
{
	int	z;

	z = -1;
	while (++z < size)
	{
		if (matrixes->helper_matrix[row][col][z] != -10)
		{
			matrixes->map_matrix[row][col] = \
				matrixes->helper_matrix[row][col][z];
			free(matrixes->helper_matrix[row][col]);
			matrixes->helper_matrix[row][col] = 0;
			return ;
		}
	}
}

int	if_only(t_matrix *matrixes, int size)
{
	int	count;
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		count = 0;
		col = -1;
		while (++col < size)
		{
			if (matrixes->helper_matrix[row][col] != 0)
				count = count_values(matrixes->helper_matrix[row][col], size);
			if (count == 1)
			{
				fix_unique_val(matrixes, row, col, size);
				cross_clear(matrixes, size);
				return (1);
			}
		}
	}
	return (0);
}
