/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:43:44 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 15:15:25 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_right_size(int **input_matrix, int ***helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;
	int	*z;

	j = -1;
	while (input_matrix[3][++j] != 0)
	{
		k = size;
		t = 1;
		while (--k != -1)
		{
			z = max_pos(helper_matrix[j][k], size);
			if ((size - input_matrix[3][j] + t) >= *z)
				break ;
			cut_values(helper_matrix[j][k], size - input_matrix[3][j] + t, size);
			++t;
		}
	}
}

static int	optimizer_right_line(int **map_matrix, int ***helper_matrix, int j, \
									int size)
{
	int	k;

	k = -1;
	while (map_matrix[j][++k] != 0)
	{
		if (helper_matrix[j][k] == 0 && map_matrix[j][k] != size - k)
			return (-1);
		if (if_in(helper_matrix[j][k], k + 1, size) == -1)
			return (-1);
		map_matrix[j][k] = size - k;
		free(helper_matrix[j][k]);
		helper_matrix[j][k] = 0;
	}
	return (0);
}

int	optimizer_right(t_matrix *matrixes, int size)
{
	int	j;

	j = -1;
	optimizer_right_size(matrixes->input_matrix, matrixes->helper_matrix, size);
	while (matrixes->input_matrix[3][++j] != 0)
	{
		if (matrixes->input_matrix[3][j] == 1)
		{
			if ((matrixes->helper_matrix[j][size - 1] == 0 && \
					matrixes->map_matrix[j][size - 1] != size) || \
					*max_pos(matrixes->helper_matrix[j][size - 1], size) != size)
				return (-1);
			free(matrixes->helper_matrix[j][size - 1]);
			matrixes->helper_matrix[j][size - 1] = 0;
			matrixes->map_matrix[j][size - 1] = size;
		}
		else if (matrixes->input_matrix[3][j] == size)
		{
			if (optimizer_right_line(matrixes->map_matrix, \
						matrixes->helper_matrix, j, size) == -1)
				return (-1);
		}
	}
	return (0);
}
