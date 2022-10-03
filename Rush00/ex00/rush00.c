/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:23 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/03 17:51:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++j <= y)
	{
		while (++i <= x)
		{
			if ((i == 1 || i == x) && (j != 1 && j != y))
				ft_putchar('|');
			else if ((j == 1 || j == y) && (i != 1 && i != x))
				ft_putchar('-');
			else if (i == 1 || i == x || j == 1 || j == y)
				ft_putchar('o');
			else
				ft_putchar(' ');
		}
		i = 0;
		ft_putchar('\n');
	}
}
