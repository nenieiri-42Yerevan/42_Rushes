/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helper_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:52:33 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 13:04:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	fill_with_size(int *helper_matrix_z, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		helper_matrix_z[i] = i + 1;
}

static int	fill_matrix(int ***helper_matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			helper_matrix[i][j] = (int *)malloc(sizeof(int) * size);
			if (!helper_matrix[i][j])
				return (free_helper(helper_matrix, i, j, size));
			fill_with_size(helper_matrix[i][j], size);
		}
	}
	return (0);
}

int	fill_helper_matrix(t_matrix *matrixes, int size)
{
	int	status;

	if (fill_matrix(matrixes->helper_matrix, size) == -1)
		return (0);
	status = optimizer_up(matrixes, size);
	if (status != -1)
		status = optimizer_down(matrixes, size);
	if (status != -1)
		status = optimizer_left(matrixes, size);
	if (status != -1)
		status = optimizer_right(matrixes, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	pair_2_2(matrixes, size);
	cross_clear(matrixes, size);
	status = pair_1_2(matrixes, size);
	if (status == -1)
		return (0);
	return (1);
}
