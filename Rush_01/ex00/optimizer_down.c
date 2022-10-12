/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:20:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 12:56:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_down_size(int **input_matrix, int **helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;

	j = -1;
	while (input_matrix[1][++j] != 0)
	{
		k = size;
		t = 1;
		while (--k != -1)
		{
			if ((size - input_matrix[1][j] + t) >= helper_matrix[k][j])
				break ;
			helper_matrix[k][j] = size - input_matrix[1][j] + t;
			++t;
		}
	}
}

static int	optimizer_down_line(int **map_matrix, int **helper_matrix, int j, \
								int size)
{
	int	k;

	k = -1;
	while (map_matrix[++k] != 0)
	{
		if (helper_matrix[k][j] == -1 && map_matrix[k][j] != size - k)
			return (-1);
		map_matrix[k][j] = size - k;
		helper_matrix[k][j] = -1;
	}
	return (0);
}

int	optimizer_down(int **map_matrix, int **input_matrix, \
						int **helper_matrix, int size)
{
	int	j;

	j = -1;
	optimizer_down_size(input_matrix, helper_matrix, size);
	while (input_matrix[1][++j] != 0)
	{
		if (input_matrix[1][j] == 1)
		{
			if (helper_matrix[size - 1][j] == -1 && \
					map_matrix[size - 1][j] != size)
				return (-1);
			helper_matrix[size - 1][j] = -1;
			map_matrix[size - 1][j] = size;
		}
		else if (input_matrix[1][j] == size)
		{
			if (optimizer_down_line(map_matrix, helper_matrix, j, size) == -1)
				return (-1);
		}
	}
	return (0);
}
