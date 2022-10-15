/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_2_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:44:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/15 15:15:50 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	del_if_found(t_matrix *matrixes, int size, int row, int col)
{
	if ((matrixes->helper_matrix[row][col] != 0) && 
		(if_in(matrixes->helper_matrix[row][col], size - 1, size) == 1))
		cut_value(matrixes->helper_matrix[row][col], size - 1, size);
}

static void	pair_2_2_up_down(t_matrix *matrixes, int size, int col)
{
	int	row;

	row = 0;
	while (++row < size - 1)
		del_if_found(matrixes, size, row, col);
}

static void	pair_2_2_left_right(t_matrix *matrixes, int size, int row)
{
	int	col;

	col = 0;
	while (++col < size - 1)
		del_if_found(matrixes, size, row, col);
}

void	pair_2_2(t_matrix *matrixes, int size)
{
	int	col;

	col = -1;
	while (++col < size)
	{
		if (matrixes->input_matrix[0][col] == 2 && \
					matrixes->input_matrix[1][col] == 2)
			pair_2_2_up_down(matrixes, size, col);
		else if (matrixes->input_matrix[2][col] == 2 && \
					matrixes->input_matrix[3][col] == 2)
			pair_2_2_left_right(matrixes, size, col);
	}
}
