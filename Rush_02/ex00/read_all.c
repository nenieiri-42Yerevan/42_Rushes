/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:13:12 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/18 13:34:21 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static char	*fill_entire(char *dict_name, char *str)
{
	int				i;
	int				dict_fd;

	dict_fd = open(dict_name, O_RDONLY);
	if (dict_fd < 0)
	{
		ft_putstr_fd("Dict open error\n", 2);
		return (0);
	}
	i = 0;
	while (read(dict_fd, str + i, 1))
		++i;
	close(dict_fd);
	str[i] = '\0';
	return (str);
}

char	*read_all(char *dict_name)
{
	char			*str;
	unsigned int	nb_chars;
	char			cur_char;
	int				dict_fd;

	nb_chars = 0;
	dict_fd = open(dict_name, O_RDONLY);
	if (dict_fd < 0)
	{
		ft_putstr_fd("Dict open error\n", 2);
		return (0);
	}
	while (read(dict_fd, &cur_char, 1))
		++nb_chars;
	str = (char *)malloc(sizeof(char) * (nb_chars + 1));
	if (!str)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	close(dict_fd);
	return (fill_entire(dict_name, str));
}
