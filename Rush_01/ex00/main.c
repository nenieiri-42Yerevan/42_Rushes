/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 15:24:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

static int	rush00(char **argv)
{
	int		size;
	int		status;
	char	**map_matrix;
	char	**input_matrix;

	size = 0;
	status = 0;
	size = parsing_argv(argv[1]);
	if (size == -1)
		ft_putstr("ERROR: Arguments are not valid!\n");
	else
	{
		map_matrix = create_map_matrix(size);
		if (matrix == 0)
			return (0);
		status = check_map(map_matrix, input_matrix);
//		while (status == 0)
//		{
//			change_matrix(matrix);
//			status = check_matrix(matrix);
//		}
		if (status == 1)
			print_map(map_matrix);
		else
			ft_putstr("ERROR: Solution does not exist!\n");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (rush00(argv));
	else
		ft_putstr("ERROR: Number of arguments is wrong!\n");
	return (0);
}
