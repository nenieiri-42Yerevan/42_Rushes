/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deep_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:35:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 13:16:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	copy_row(int *src_matrix, int *dest_matrix, int size)
{
	int	col;

	col = -1;
	while (++col < size)
		dest_matrix[col] = src_matrix[col];
}

static void	copy_2d_input(int **src_matrix, int **dest_matrix, int size)
{
	int	row;

	row = -1;
	while (src_matrix[++row] != 0)
		copy_row(src_matrix[row], dest_matrix[row], size);
}

static void	copy_2d_map(int **src_matrix, int **dest_matrix, int size)
{
	int	row;

	row = -1;
	while (++row < size)
		copy_row(src_matrix[row], dest_matrix[row], size);
}

static int	copy_3d(int ***src_matrix, int ***dest_matrix, int size)
{
	int	row;
	int	col;

	row = -1;
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			if (src_matrix[row][col] == 0)
			{
				dest_matrix[row][col] = 0;
				continue ;
			}
			dest_matrix[row][col] = (int *)malloc(sizeof(int) * size);
			if (!dest_matrix[row][col])
				return (free_helper(dest_matrix, row, col, size));
			copy_row(src_matrix[row][col], dest_matrix[row][col], size);
		}
	}
	return (0);
}

int	deep_copy(t_matrix *matrixes, t_matrix *tmp, int size)
{
	copy_2d_input(matrixes->input_matrix, tmp->input_matrix, size);
	copy_2d_map(matrixes->map_matrix, tmp->map_matrix, size);
	if (copy_3d(matrixes->helper_matrix, tmp->helper_matrix, size) == -1)
		return (-1);
	return (0);
}
