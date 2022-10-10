/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:24:09 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 13:26:45 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int c)
{
	char	*new_s;

	new_s = (char *)s;
	while (*new_s != '\0')
	{
		if (*new_s == c)
			return (new_s);
		++new_s;
	}
	if (c == '\0' && *new_s == '\0')
		return (new_s);
	return (0);
}
