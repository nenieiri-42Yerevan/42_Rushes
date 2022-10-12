/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_input_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:28:25 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 11:54:04 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	fill_input_matrix(char *argv, int **input_matrix, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (input_matrix[++i] != 0)
	{
		j = -1;
		while (++j < size)
		{
			while (!(argv[k] == '\0' || argv[k] != ' '))
				++k;
			if (argv[k] - 48 > size)
			{
				ft_putstr("ERROR: ");
				ft_putstr(&argv[k]);
				ft_putstr(": Argument is not valid!\n");
				return (0);
			}
			input_matrix[i][j] = argv[k] - 48;
			++k;
		}
	}
	return (1);
}
