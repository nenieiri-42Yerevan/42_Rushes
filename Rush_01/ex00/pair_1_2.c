/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_1_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:52:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/15 14:27:04 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int pair_1_2_down(t_matrix *matrixes, int size, int col)
{
	if ((matrixes->helper_matrix[0][col] == 0) || 
		(if_in(matrixes->helper_matrix[0][col], size - 1, size) == 0))
		return (-1);
	matrixes->map_matrix[0][col] = size - 1;
	free(matrixes->helper_matrix[0][col]);
	matrixes->helper_matrix[0][col] = 0;
	return (1);
}

static int pair_1_2_up(t_matrix *matrixes, int size, int col)
{
	if ((matrixes->helper_matrix[size - 1][col] == 0) || 
		(if_in(matrixes->helper_matrix[size - 1][col], size - 1, size) == 0))
		return (-1);
	matrixes->map_matrix[size - 1][col] = size - 1;
	free(matrixes->helper_matrix[size - 1][col]);
	matrixes->helper_matrix[size - 1][col] = 0;
	return (1);
}

static int pair_1_2_left(t_matrix *matrixes, int size, int row)
{
	if ((matrixes->helper_matrix[row][size - 1] == 0) || 
		(if_in(matrixes->helper_matrix[row][size - 1], size - 1, size) == 0))
		return (-1);
	matrixes->map_matrix[row][size - 1] = size - 1;
	free(matrixes->helper_matrix[row][size - 1]);
	matrixes->helper_matrix[row][size - 1] = 0;
	return (1);
}

static int pair_1_2_right(t_matrix *matrixes, int size, int row)
{
	if ((matrixes->helper_matrix[row][0] == 0) || 
		(if_in(matrixes->helper_matrix[row][0], size - 1, size) == 0))
		return (-1);
	matrixes->map_matrix[row][0] = size - 1;
	free(matrixes->helper_matrix[row][0]);
	matrixes->helper_matrix[row][0] = 0;
	return (1);
}

int	pair_1_2(t_matrix *matrixes, int size)
{
	int	res;
	int	col;

	res = 0;
	col = -1;
	while (++col < size && res != -1)
	{
		if (matrixes->input_matrix[0][col] == 1 && \
					matrixes->input_matrix[1][col] == 2)
			res = pair_1_2_up(matrixes, size, col);
		else if (matrixes->input_matrix[0][col] == 2 && \
					matrixes->input_matrix[1][col] == 1)
			res = pair_1_2_down(matrixes, size, col);
		else if (matrixes->input_matrix[2][col] == 1 && \
					matrixes->input_matrix[3][col] == 2)
			res = pair_1_2_left(matrixes, size, col);
		else if (matrixes->input_matrix[2][col] == 2 && \
					matrixes->input_matrix[3][col] == 1)
			res = pair_1_2_right(matrixes, size, col);
		if (res == 1)
			cross_clear(matrixes, size);
	}
	if (res == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (-1);
	}
	return (0);
}
