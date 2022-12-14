/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:17:37 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/04 15:57:45 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

void	rush(int x, int y);

int	main(void)
{
	rush(5, 3);
	printf("\n");
	rush(5, 1);
	printf("\n");
	rush(1, 1);
	printf("\n");
	rush(1, 5);
	printf("\n");
	rush(4, 4);
	printf("\n");
	rush(-5, 5);
	printf("\n");
	rush(5, -5);
	printf("\n");
	rush(-5, -5);
	return (0);
}
