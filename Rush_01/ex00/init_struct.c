/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:58:24 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 12:02:07 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	**create_matrix_2d(int height, int width)
{
	int	**matrix;
	int	i;

	i = -1;
	matrix = (int **)malloc(sizeof(int *) * (height + 1));
	if (!matrix)
		return (0);
	matrix[height] = 0;
	while (++i < height)
	{
		matrix[i] = (int *)malloc(sizeof(int) * (width + 1));
		if (!matrix[i])
		{
			free_matrix_2d(matrix, i);
			return (0);
		}
		matrix[i][width] = 0;
	}
	return (matrix);
}

static void	free_matrix_3d_f(int ***matrix, int i)
{
	int	x;

	x = -1;
	if (matrix == 0)
		return ;
	while (++x < i)
	{
		free(matrix[x]);
		matrix[x] = 0;
	}
	free(matrix);
	matrix = 0;
}

static void	set_null(int ***matrix, int height, int width)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
		{
			matrix[i][j] = 0;
		}
	}
}

static int	***create_matrix_3d(int height, int width)
{
	int	***matrix;
	int	i;

	i = -1;
	matrix = (int ***)malloc(sizeof(int **) * (height + 1));
	if (!matrix)
		return (0);
	matrix[height] = 0;
	while (++i < height)
	{
		matrix[i] = (int **)malloc(sizeof(int *) * (width + 1));
		if (!matrix[i])
		{
			free_matrix_3d_f(matrix, i);
			return (0);
		}
		matrix[i][width] = 0;
	}
	set_null(matrix, height, width);
	return (matrix);
}

int	init_struct(t_matrix *matrixes, int size)
{
	matrixes->map_matrix = create_matrix_2d(size, size);
	if (matrixes->map_matrix == 0)
		return (0);
	matrixes->input_matrix = create_matrix_2d(4, size);
	if (matrixes->input_matrix == 0)
	{
		free_matrix_2d(matrixes->map_matrix, size);
		return (0);
	}
	matrixes->helper_matrix = create_matrix_3d(size, size);
	if (matrixes->helper_matrix == 0)
	{
		free_matrix_2d(matrixes->map_matrix, size);
		free_matrix_2d(matrixes->input_matrix, size);
		return (0);
	}
	fill_map_matrix(matrixes->map_matrix, size);
	return (1);
}
