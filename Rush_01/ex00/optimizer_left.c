/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:39:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 17:24:30 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_left_size(int **input_matrix, int ***helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;
	int	*z;

	j = -1;
	while (input_matrix[2][++j] != 0)
	{
		k = -1;
		t = 1;
		while (helper_matrix[j][++k] != 0)
		{
			if (helper_matrix[j][k] == 0)
				break ;
			z = max_pos(helper_matrix[j][k], size);
			if ((size - input_matrix[2][j] + t) >= *z)
				break ;
			cut_values(helper_matrix[j][k], size - input_matrix[2][j] + t, size);
			++t;
		}
	}
}

static int	optimizer_left_line(int **map_matrix, int ***helper_matrix, int j, \
								int size)
{
	int	k;

	k = -1;
	while (map_matrix[j][++k] != 0)
	{
		if (helper_matrix[j][k] == 0 && map_matrix[j][k] != k + 1)
			return (-1);
		if (if_in(helper_matrix[j][k], k + 1, size) == -1)
			return (-1);
		map_matrix[j][k] = k + 1;
		free(helper_matrix[j][k]);
		helper_matrix[j][k] = 0;
	}
	return (0);
}

int	optimizer_left(t_matrix *matrixes, int size)
{
	int	j;

	j = -1;
	optimizer_left_size(matrixes->input_matrix, matrixes->helper_matrix, size);
	while (matrixes->input_matrix[2][++j] != 0)
	{
		if (matrixes->input_matrix[2][j] == 1)
		{
			if ((matrixes->helper_matrix[j][0] == 0 && \
					matrixes->map_matrix[j][0] != size) || \
					*max_pos(matrixes->helper_matrix[j][0], size) != size)
				return (-1);
			free(matrixes->helper_matrix[j][0]);
			matrixes->helper_matrix[j][0] = 0;
			matrixes->map_matrix[j][0] = size;
		}
		else if (matrixes->input_matrix[2][j] == size)
		{
			if (optimizer_left_line(matrixes->map_matrix, \
						matrixes->helper_matrix, j, size) == -1)
				return (-1);
		}
	}
	return (0);
}
