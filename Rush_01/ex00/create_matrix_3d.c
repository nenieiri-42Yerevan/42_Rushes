/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix_3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:56:10 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 13:04:18 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

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
			free_matrix_2d(matrix, i);
			return (0);
		}
		matrix[i][width] = 0;
	}
	return (matrix);
}
