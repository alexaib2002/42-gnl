/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/04 21:12:53 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

const static size_t buf_size = 5; // TODO replace by BUFSIZE

/*
TODO:
 - malloc security checks (after malloc and such)
 - Hardcoded buffer and size
 - If buffer is filled, that means current line continues, but my GNL doesn't think so!
*/
char	*get_next_line(int fd)
{
	char *buf;
	t_list *buflst;
	size_t i;
	ssize_t res;
	static size_t fp = 0;

	buf = ft_calloc(buf_size, sizeof(char));
	if (!buf)
		return (NULL);
	res = 1; // FIXME is this the right way to enter the loop?
	buflst = NULL;
	while (res > 0)
	{
		i = 0;
		while (i < buf_size)
		{
			res = read(fd, buf + i, 1);
			if (buf[i] == '\n')
				break;
				// res = 0; // hacky, forces an exit by reporting EOF >.<
			i++;
		}
		ft_lstadd_back(&buflst, ft_strlstnew(buf));
		if (buf[i] == '\n') // FIXME should be better... maybe put it on loop definition?
			break;
		ft_bzero(buf, buf_size);
	}
	// EOF check
	if (!*buf)
		return (NULL);
	// TODO hay que concatenar la lista
	char *final_str = ft_merge_strlst(buflst);
	return (final_str);
}
