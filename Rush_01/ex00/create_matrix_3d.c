/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:56:10 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 15:56:52 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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

int	***create_matrix_3d(int height, int width)
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
	return (matrix);
}
