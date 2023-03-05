/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/05 15:48:08 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*final_str;
	t_list		*buflst;
	size_t		i;
	ssize_t		res;

	res = 1;
	buflst = NULL;
	final_str = NULL;
	if (buf == NULL)
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (res > 0)
	{
		i = 0;
		res = read(fd, buf, BUFFER_SIZE);
		while (i < BUFFER_SIZE || buf[i] != '\n')
			i++;
		ft_lstadd_back(&buflst, ft_strlstnew(buf));
		if (buf[i] == '\n')
			break ;
		ft_bzero(buf, BUFFER_SIZE);
	}
	if (*buf)
		final_str = ft_merge_strlst(buflst);
	if (!res)
		free(buf);
	ft_lstclear(&buflst, &free);
	return (final_str);
}
