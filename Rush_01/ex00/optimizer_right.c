/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:43:44 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 12:56:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_right_size(int **input_matrix, int **helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;

	j = -1;
	while (input_matrix[3][++j] != 0)
	{
		k = size;
		t = 1;
		while (--k != -1)
		{
			if ((size - input_matrix[3][j] + t) >= helper_matrix[j][k])
				break ;
			helper_matrix[j][k] = size - input_matrix[3][j] + t;
			++t;
		}
	}
}

static int	optimizer_right_line(int **map_matrix, int **helper_matrix, int j, \
									int size)
{
	int	k;

	k = -1;
	while (map_matrix[j][++k] != 0)
	{
		if (helper_matrix[j][k] == -1 && map_matrix[j][k] != size - k)
			return (-1);
		map_matrix[j][k] = size - k;
		helper_matrix[j][k] = -1;
	}
	return (0);
}

int	optimizer_right(int **map_matrix, int **input_matrix, int **helper_matrix, \
					int size)
{
	int	j;

	j = -1;
	optimizer_right_size(input_matrix, helper_matrix, size);
	while (input_matrix[3][++j] != 0)
	{
		if (input_matrix[3][j] == 1)
		{
			if (helper_matrix[j][size - 1] == -1 && \
					map_matrix[j][size - 1] != size)
				return (-1);
			helper_matrix[j][size - 1] = -1;
			map_matrix[j][size - 1] = size;
		}
		else if (input_matrix[3][j] == size)
		{
			if (optimizer_right_line(map_matrix, helper_matrix, j, size) == -1)
				return (-1);
		}
	}
	return (0);
}
