/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:42:56 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/13 14:48:33 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	free_matrix_3d(int ***matrix)
{
	int	i;
	int	j;

	i = -1;
	if (matrix == 0)
		return ;
	while (matrix[++i] != 0)
	{
		j = -1;
		while (matrix[i][++j] != 0)
		{
			free(matrix[i][j]);
			matrix[i][j] = 0;
		}
		free(matrix[i]);
		matrix[i] = 0;
	}
	free(matrix);
	matrix = 0;
}
