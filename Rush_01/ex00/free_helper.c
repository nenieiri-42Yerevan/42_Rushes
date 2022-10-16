/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:03:47 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 13:04:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	free_helper(int ***helper_matrix, int i, int j, int size)
{
	int	k;

	k = -1;
	while (++k < j)
	{
		free(helper_matrix[i][k]);
		helper_matrix[i][k] = 0;
	}
	free_matrix_3d(helper_matrix, size);
	return (-1);
}
