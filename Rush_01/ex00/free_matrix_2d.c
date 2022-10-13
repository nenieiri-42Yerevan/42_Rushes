/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:31:54 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 12:43:29 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_matrix_2d(int **matrix, int i)
{
	int	x;

	x = -1;
	if (matrix == 0)
		return ;
	while (++x < i)
	{
		free(matrix[x]);
		matrix[x] = 0;
	}
	free(matrix);
	matrix = 0;
}
