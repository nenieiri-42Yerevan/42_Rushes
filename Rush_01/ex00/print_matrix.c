/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:38:03 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 15:11:47 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

void	print_matrix(char **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (matrix[++i] != 0)
	{
		j = -1;
		while (matrix[i][++j] != 0)
		{
			ft_putchar(matrix[i][j] + 48);
			if (matrix[i][j + 1] != '\0')
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}
