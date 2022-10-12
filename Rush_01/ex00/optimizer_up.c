/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:15:33 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 12:54:22 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_up_size(int **input_matrix, int **helper_matrix, int size)
{
	int	j;
	int	k;
	int	t;

	j = -1;
	while (input_matrix[0][++j] != 0)
	{
		k = -1;
		t = 1;
		while (helper_matrix[++k] != 0)
		{
			if ((size - input_matrix[0][j] + t) >= helper_matrix[k][j])
				break ;
			helper_matrix[k][j] = size - input_matrix[0][j] + t;
			++t;
		}
	}
}

static int	optimizer_up_line(int **map_matrix, int **helper_matrix, int j)
{
	int	k;

	k = -1;
	while (map_matrix[++k] != 0)
	{
		if (helper_matrix[k][j] == -1 && map_matrix[k][j] != k + 1)
			return (-1);
		map_matrix[k][j] = k + 1;
		helper_matrix[k][j] = -1;
	}
	return (0);
}

int	optimizer_up(int **map_matrix, int **input_matrix, \
					int **helper_matrix, int size)
{
	int	j;

	j = -1;
	optimizer_up_size(input_matrix, helper_matrix, size);
	while (input_matrix[0][++j] != 0)
	{
		if (input_matrix[0][j] == 1)
		{
			if (helper_matrix[0][j] == -1 && map_matrix[0][j] != size)
				return (-1);
			helper_matrix[0][j] = -1;
			map_matrix[0][j] = size;
		}
		else if (input_matrix[0][j] == size)
		{
			if (optimizer_up_line(map_matrix, helper_matrix, j) == -1)
				return (-1);
		}
	}
	return (0);
}
