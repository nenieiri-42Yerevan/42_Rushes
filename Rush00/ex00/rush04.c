/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:01 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/04 15:56:57 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j <= y && x > 0)
	{
		while (++i <= x)
		{
			if ((i == 1 && j == 1) || (i == x && j == y && i != 1 && j != 1))
				ft_putchar('A');
			else if ((i == 1 && j == y) || (j == 1 && i == x))
				ft_putchar('C');
			else if (i == 1 || i == x || j == 1 || j == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		i = 0;
		ft_putchar('\n');
	}
}
