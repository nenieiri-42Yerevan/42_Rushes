/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_1_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 13:52:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 16:14:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	pair_1_2_checker(t_matrix *matrixes, int size, int row, int col)
{
	if (matrixes->helper_matrix[row][col] == 0 && \
						matrixes->map_matrix[row][col] != size - 1)
		return (-1);
	if (matrixes->helper_matrix[row][col] == 0)
		return (1);
	if (if_in(matrixes->helper_matrix[row][col], size - 1, size) == 0)
		return (-1);
	matrixes->map_matrix[row][col] = size - 1;
	free(matrixes->helper_matrix[row][col]);
	matrixes->helper_matrix[row][col] = 0;
	return (1);
}

static int	result_value(int res)
{
	if (res == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (-1);
	}
	return (0);
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
			res = pair_1_2_checker(matrixes, size, size - 1, col);
		else if (matrixes->input_matrix[0][col] == 2 && \
				matrixes->input_matrix[1][col] == 1)
			res = pair_1_2_checker(matrixes, size, 0, col);
		else if (matrixes->input_matrix[2][col] == 1 && \
				matrixes->input_matrix[3][col] == 2)
			res = pair_1_2_checker(matrixes, size, col, size - 1);
		else if (matrixes->input_matrix[2][col] == 2 && \
				matrixes->input_matrix[3][col] == 1)
			res = pair_1_2_checker(matrixes, size, col, 0);
		if (res == 1)
			cross_clear(matrixes, size);
	}
	return (result_value(res));
}
