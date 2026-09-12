/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casampai <casampai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:08:06 by casampai          #+#    #+#             */
/*   Updated: 2026/09/12 16:47:55 by casampai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*find_chr(const char *s, int c)
{
	char	*ptr_s;

	if (!s)
		return (NULL);
	ptr_s = (char *)s;
	while (*ptr_s)
	{
		if (*ptr_s == c)
			return (ptr_s);
		ptr_s++;
	}
	if (*ptr_s == (char)c)
		return (ptr_s);
	return (NULL);
}

int	get_str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*init_stash(char *stash)
{
	if (!stash)
	{
		stash = (char *)malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	return (stash);
}

char	*join_string(char *stash, char *buffer)
{
	char	*new_stash;
	int		i;
	int		j;

	stash = init_stash(stash);
	if (!stash || !buffer)
		return (free(stash), NULL);
	new_stash = malloc(sizeof(char)
			* (get_str_len(stash) + get_str_len(buffer) + 1));
	if (!new_stash)
		return (free(stash), NULL);
	i = 0;
	j = 0;
	while (stash[j])
		new_stash[i++] = stash[j++];
	j = 0;
	while (buffer[j])
		new_stash[i++] = buffer[j++];
	new_stash[i] = '\0';
	free(stash);
	return (new_stash);
}
