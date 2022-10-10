/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 14:46:49 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static int	rush00(char **argv)
{
	int		size;
	char	**matrix;

	size = 0;
	size = parsing_argv(argv[1]);
	if (size == -1)
		ft_putstr("ERROR: Arguments not valid\n");
	else
	{
		matrix = create_matrix(size);
		if (matrix == 0)
			return (0);
		print_matrix(matrix, size);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (rush00(argv));
	else
		ft_putstr("ERROR: Arguments count\n");
	return (0);
}
