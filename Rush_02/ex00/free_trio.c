/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_trio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:24:36 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/22 11:25:08 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_trio(t_trio *trio)
{
	if (trio->hundred != NULL)
		free(trio->hundred);
	if (trio->hundred_units != NULL)
		free(trio->hundred_units);
	if (trio->dozen != NULL)
		free(trio->dozen);
	if (trio->unit != NULL)
		free(trio->unit);
	if (trio != NULL)
		free(trio);
}
