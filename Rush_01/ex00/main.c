/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 18:12:37 by vismaily         ###   ########.fr       */
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
		if (map_matrix == 0)
			return (0);
		input_matrix = create_input_matrix(argv[1], size);
		if (input_matrix == 0)
			return (0);
		status = check_map(map_matrix, input_matrix, size);
		while (status == 0)
		{
			change_matrix(map_matrix, size);
			status = check_map(map_matrix, input_matrix, size);
		}
		if (status == 1)
			print_map(input_matrix);
		else
			ft_putstr("ERROR: Solution does not exist!\n");
		free_matrix(input_matrix, 4);
		free_matrix(map_matrix, size);
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
