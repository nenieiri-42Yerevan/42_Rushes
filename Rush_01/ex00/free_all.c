/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:11:51 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 12:12:16 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	free_all(t_matrix *matrixes, int size)
{
	free_matrix_2d(matrixes->input_matrix, 4);
	free_matrix_2d(matrixes->map_matrix, size);
	free_matrix_3d(matrixes->helper_matrix, size);
	return (0);
}
