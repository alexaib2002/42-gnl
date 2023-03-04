/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/04 18:55:47 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const static size_t buf_size = 40;

/*
TODO:
 - malloc security checks (after malloc and such)
 - Hardcoded buffer and size
 - If buffer is filled, that means current line continues, but my GNL doesn't think so!
*/
char	*get_next_line(int fd)
{
	char *buf;
	size_t i;
	ssize_t res;

	i = 0;
	buf = ft_calloc(buf_size, sizeof(char));
	if (!buf)
		return (NULL);
	while (res > 0 && i < buf_size)
	{
		res = read(fd, buf + i, 1);
		if (buf[i] == '\n')
			break;
		i++;
	}
	// EOF check
	if (!*buf)
		return (NULL);
	return (buf);
}
