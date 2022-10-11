/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:38:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/11 15:18:03 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

void	print_map(int **map_matrix)
{
	int	i;
	int	j;

	i = -1;
	while (map_matrix[++i] != 0)
	{
		j = -1;
		while (map_matrix[i][++j] != 0)
		{
			ft_putchar(map_matrix[i][j] + 48);
			if (map_matrix[i][j + 1] != '\0')
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
