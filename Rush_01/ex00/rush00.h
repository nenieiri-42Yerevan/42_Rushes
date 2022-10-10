/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/10 17:49:55 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH00_H
# define RUSH00_H

#include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
int		parsing_argv(char *argv);
char	**create_input_matrix(char *argv, int size);
char	**create_map_matrix(int size);
void	free_matrix(char **matrix, int i);
void	print_map(char **matrix);
int		check_map(char **map_matrix, char **input_matrix, int size);
int		check_end(char **map_matrix, int size);
void	change_matrix(char **map_matrix, int size);

#endif
