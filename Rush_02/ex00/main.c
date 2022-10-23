/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:00:30 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 11:41:29 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main(int argc, char **argv)
{
	char	*number;
	char	*dict;

	if (argc > 3)
		ft_putstr_fd("Error\n", 2);
	else if (argc != 1)
	{
		if (argc == 2)
		{
			number = parse_number(argv[1]);
			dict = read_all("numbers.dict");
		}
		else
		{
			number = parse_number(argv[2]);
			dict = read_all(argv[1]);
		}
		if (number == 0)
			ft_putstr_fd("Error\n", 2);
		else if (dict != 0)
			run(dict, number);
	}
	while (1) ;
	return (0);
}
