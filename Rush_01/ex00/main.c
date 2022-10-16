/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:29:21 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/16 12:36:29 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static int	init(char *argv, t_matrix *matrixes, int size)
{
	if (init_struct(matrixes, size) == 0)
	{
		free_all(matrixes, size);
		return (0);
	}
	if (fill_input_matrix(argv, matrixes->input_matrix, size) == 0)
	{
		free_all(matrixes, size);
		return (0);
	}
	if (fill_helper_matrix(matrixes, size) == 0)
	{
		free_all(matrixes, size);
		return (0);
	}
	return (1);
}

static int	rush00(char **argv, int size)
{
	int			status;
	t_matrix	matrixes;

	status = 0;
	init(argv[1], &matrixes, size);
	status = routine(&matrixes, size);
/*	while (status == 0)
	{
		status = change_matrix(&matrixes, size);
		while (status == 1)
			status = change_matrix(&matrixes, size);
*/		if (status == -1)
		{
			ft_putstr("ERROR: Solution does not exist!\n");
//			break ;
		}
/*		status = check_map(&matrixes, size);
	}
*/	if (status == 1)
		print_map(matrixes.map_matrix);
	free_all(&matrixes, size);
	return (0);
}

int	main(int argc, char **argv)
{
	int		size;

	size = 0;
	if (argc == 2)
	{
		size = parsing_argv(argv[1]);
		if (size == -1)
			ft_putstr("ERROR: Arguments are not valid!\n");
		else
			return (rush00(argv, size));
	}
	else
		ft_putstr("ERROR: Number of arguments is wrong!\n");
	return (0);
}
