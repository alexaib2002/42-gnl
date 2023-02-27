/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/02/27 14:17:16 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int buf_size = 42;

static void	fill_buffer(int fd, const char *buf)
{
	int i; // iterador
	int res;

	i = 0;
	read(fd, buf, buf_size);
	while (i < buf_size && res)
		res = read(fd, buf[i++], buf_size);
}

char	*get_next_line(int fd)
{
	const char *buf = calloc(buf_size, sizeof(char)); // FIXME hardcoded buffer and size
	int i;

	fill_buffer(fd, buf);
	// read string from buffer
	printf("%s\n", buf);
	free(buf);
	return (NULL);
}
