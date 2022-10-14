/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:20:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/14 11:36:38 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	optimizer_down_size(int **input_matrix, int ***helper_matrix, \
								int size)
{
	int	j;
	int	k;
	int	t;
	int	*z;

	j = -1;
	while (input_matrix[1][++j] != 0)
	{
		k = size;
		t = 1;
		while (--k != -1)
		{
			if (helper_matrix[k][j] == 0)
				break ;
			z = max_pos(helper_matrix[k][j], size);
			if ((size - input_matrix[1][j] + t) >= *z)
				break ;
			cut_values(helper_matrix[k][j], size - input_matrix[1][j] + t, \
						size);
			++t;
		}
	}
}

static int	optimizer_down_line(int **map_matrix, int ***helper_matrix, int j, \
								int size)
{
	int	k;

	k = -1;
	while (map_matrix[++k] != 0)
	{
		if (helper_matrix[k][j] == 0 && map_matrix[k][j] != size - k)
			return (-1);
		if (helper_matrix[k][j] == 0)
			continue ;
		if (if_in(helper_matrix[k][j], size - k, size) == -1)
			return (-1);
		map_matrix[k][j] = size - k;
		free(helper_matrix[k][j]);
		helper_matrix[k][j] = 0;
	}
	return (0);
}

int	optimizer_down(t_matrix *matrixes, int size)
{
	int	j;

	j = -1;
	optimizer_down_size(matrixes->input_matrix, matrixes->helper_matrix, size);
	while (matrixes->input_matrix[1][++j] != 0)
	{
		if (matrixes->input_matrix[1][j] == 1)
		{
			if (matrixes->helper_matrix[size - 1][j] == 0 && \
					matrixes->map_matrix[size - 1][j] != size)
				return (-1);
			if (matrixes->helper_matrix[size - 1][j] == 0)
				continue ;
			if (*max_pos(matrixes->helper_matrix[size - 1][j], size) != size)
				return (-1);
			free(matrixes->helper_matrix[size - 1][j]);
			matrixes->helper_matrix[size - 1][j] = 0;
			matrixes->map_matrix[size - 1][j] = size;
		}
		else if (matrixes->input_matrix[1][j] == size)
			if (optimizer_down_line(matrixes->map_matrix, \
						matrixes->helper_matrix, j, size) == -1)
				return (-1);
	}
	return (0);
}
