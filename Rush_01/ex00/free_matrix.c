/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:31:54 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 12:23:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

void	free_matrix(char **matrix, int i)
{
	while (i != -1)
	{
		i = i - 1;
		free(matrix[i]);
		matrix[i] = 0;
	}
	free(matrix);
	matrix = 0;
}
