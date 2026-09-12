/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casampai, fnunes-d <casampai, fnunes-d@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:03:49 by casampai          #+#    #+#             */
/*   Updated: 2026/09/12 06:03:45 by casampai, f      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE  10
#endif

char    *get_next_line(int fd);
char	*find_chr(const char *s, int c);
int     get_str_len(char *str);
char	*join_string(char *stash, char *buffer);
