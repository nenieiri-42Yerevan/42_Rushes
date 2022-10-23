/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 11:20:34 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 11:39:58 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_dict(t_dict **my_dict)
{
	int	i;

	if (my_dict == 0)
		return ;
	i = -1;
	while (my_dict[++i] != 0)
	{
		if (my_dict[i]->key != 0)
			free(my_dict[i]->key);
		if (my_dict[i]->value != 0)
			free(my_dict[i]->value);
		if (my_dict[i] != 0)
			free(my_dict[i]);
	}
	free(my_dict);
}
