/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 19:50:22 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/22 15:13:51 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	size_t	i;
	char	*strtrim;

	if (!s1)
		return (0);
	beg = 0;
	while (s1[beg] != '\0' && ft_strchr(set, s1[beg]))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_strchr(set, s1[end]))
		end--;
	if (beg <= end)
		strtrim = malloc(sizeof(char) * (end - beg + 2));
	else
		strtrim = malloc(sizeof(char));
	if (!strtrim)
		return (0);
	i = 0;
	while (beg <= end)
		strtrim[i++] = s1[beg++];
	strtrim[i] = '\0';
	return (strtrim);
}
