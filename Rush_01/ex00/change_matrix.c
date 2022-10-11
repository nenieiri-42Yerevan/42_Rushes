/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:50:08 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 17:28:40 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

int	change_matrix(int **map_matrix, int **helper_matrix, int size)
{
	int	i;
	int	j;

	i = -1;
//	print_map(map_matrix);
//	usleep(500);
//	ft_putchar('\n');
	while (map_matrix[++i] != 0)
	{
		j = -1;
		while (map_matrix[i][++j] != 0)
		{
			if (map_matrix[i + 1] == 0 && map_matrix[i][j + 1] == 0 && \
					(map_matrix[i][j] == helper_matrix[i][j] || helper_matrix[i][j] == -1))
				return (-1);
			if (helper_matrix[i][j] == -1)
				continue ;
			if (map_matrix[i][j] == size)
				map_matrix[i][j] = 1;
			else if (map_matrix[i][j] < size)
			{
				map_matrix[i][j] += 1;
				return (0);
			}
		}
	}
	return (0);
}
