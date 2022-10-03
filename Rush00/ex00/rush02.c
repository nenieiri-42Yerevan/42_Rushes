/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:45:58 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/03 16:46:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (++j <= y)
	{
		while (++i <= x)
		{
			if (j == 1 && (i == 1 || i == x))
				ft_putchar('A');
			else if (j == y && (i == 1 || i == x))
				ft_putchar('C');
			else if (j == 1 || i == 1 || j == y || i == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
		i = 0;
		ft_putchar('\n');
	}
}
