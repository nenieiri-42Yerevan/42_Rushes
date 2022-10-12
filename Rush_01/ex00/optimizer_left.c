/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:39:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 12:50:15 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_left_size(int **input_matrix, int **helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;

	j = -1;
	while (input_matrix[2][++j] != 0)
	{
		k = -1;
		t = 1;
		while (helper_matrix[j][++k] != 0)
		{
			if ((size - input_matrix[2][j] + t) >= helper_matrix[j][k])
				break ;
			helper_matrix[j][k] = size - input_matrix[2][j] + t;
			++t;
		}
	}
}

static int	optimizer_left_line(int **map_matrix, int **helper_matrix, int j)
{
	int	k;

	k = -1;
	while (map_matrix[j][++k] != 0)
	{
		if (helper_matrix[j][k] == -1 && map_matrix[j][k] != k + 1)
			return (-1);
		map_matrix[j][k] = k + 1;
		helper_matrix[j][k] = -1;
	}
	return (0);
}

int	optimizer_left(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	j;

	j = -1;
	optimizer_left_size(input_matrix, helper_matrix, size);
	while (input_matrix[2][++j] != 0)
	{
		if (input_matrix[2][j] == 1)
		{
			if (helper_matrix[j][0] == -1 && map_matrix[j][0] != size)
				return (-1);
			helper_matrix[j][0] = -1;
			map_matrix[j][0] = size;
		}
		else if (input_matrix[2][j] == size)
		{
			if (optimizer_left_line(map_matrix, helper_matrix, j) == -1)
				return (-1);
		}
	}
	return (0);
}
