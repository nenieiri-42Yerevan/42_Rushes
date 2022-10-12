/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_helper_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:52:33 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 12:59:09 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	fill_0(int **helper_matrix, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			helper_matrix[i][j] = size;
	}
}

int	fill_helper_matrix(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size)
{
	int	status;

	fill_0(helper_matrix, size);
	status = optimizer_up(map_matrix, input_matrix, helper_matrix, size);
	if (status != -1)
		status = optimizer_down(map_matrix, input_matrix, helper_matrix, size);
	if (status != -1)
		status = optimizer_left(map_matrix, input_matrix, helper_matrix, size);
	if (status != -1)
		status = optimizer_right(map_matrix, input_matrix, helper_matrix, size);
	if (status == -1)
	{
		ft_putstr("ERROR: Solution does not exist!\n");
		return (0);
	}
	return (1);
}
