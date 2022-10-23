/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:39:33 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/23 12:22:20 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static void	display_units(char *str, t_dict **dict, int *f)
{
	int	i;

	i = -1;
	while (dict[++i] != 0 && str != 0)
	{
		if (ft_strcmp(str, dict[i]->key) == 0)
		{
			if (*f != 0)
				ft_putstr_fd(" ", 1);
			*f = 1;
			ft_putstr_fd(dict[i]->value, 1);
			return ;
		}
	}
}

static size_t	dict_max_len(t_dict **dict)
{
	int		i;
	size_t	max;
	size_t	length;

	i = -1;
	max = 0;
	if (dict == 0)
		return (0);
	while (dict[++i] != 0)
	{
		length = ft_strlen(dict[i]->key);
		if (length > max)
			max = length;
	}
	return (max + 2);
}

static int	is_good(t_trio *trio)
{
	if (trio->hundred_units == 0 && trio->unit == 0 && trio->dozen == 0)
		return (0);
	return (1);
}

static void	convert_to_text(char *nb, t_dict **dict)
{
	int		i;
	int		size;
	int		f;
	char	*tmp;
	t_trio	*trio;

	i = -1;
	f = 0;
	tmp = nb;
	size = ft_strlen(nb) / 3;
	while (++i < size)
	{
		trio = trio_to_struct(nb);
		if (!trio)
			return ;
		display_units(trio->hundred_units, dict, &f);
		display_units(trio->hundred, dict, &f);
		display_units(trio->dozen, dict, &f);
		display_units(trio->unit, dict, &f);
		if (i != size - 1 && is_good(trio) == 1)
			display_zero(size - i - 1, dict);
		free_trio(trio);
		nb += 3;
	}
	free(tmp);
}

void	run(char *dict, char *number)
{
	t_dict	**my_dict;
	int		zero;
	char	*nb;

	zero = 0;
	my_dict = get_dict(dict);
	if (dict == NULL || ft_strlen(number) > dict_max_len(my_dict))
	{
		ft_putstr_fd("Dict Error\n", 2);
		return ;
	}
	if (*number == '0')
	{
		display_units(number, my_dict, &zero);
		free_dict(my_dict);
		return ;
	}
	nb = format_string(number);
	if (nb != 0)
	{
		convert_to_text(nb, my_dict);
		write(1, "\n", 1);
	}
	free_dict(my_dict);
	return ;
}
