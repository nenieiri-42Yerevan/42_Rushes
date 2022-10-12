/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <nenie_iri@mail.ru>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:55:42 by vismaily          #+#    #+#             */
/*   Updated: 2022/10/12 16:30:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int c);
int		parsing_argv(char *argv);
int		**create_matrix(int height, int width);
void	fill_map_matrix(int **map_matrix, int size);
int		fill_input_matrix(char *argv, int **input_matrix, int size);
void	free_matrix(int **matrix, int i);
void	print_map(int **matrix);
int		check_map(int **map_matrix, int **input_matrix, int size);
int		change_matrix(int **map_matrix, int **helper_matrix);

int		fill_helper_matrix(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size);
int		optimizer_up(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size);
int		optimizer_down(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size);
int		optimizer_left(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size);
int		optimizer_right(int **map_matrix, int **input_matrix, \
							int **helper_matrix, int size);

#endif
