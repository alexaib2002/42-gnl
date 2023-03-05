/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexaib <alexaib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/05 15:27:26 by alexaib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*final_str;
	t_list	*buflst;
	size_t	i;
	ssize_t	res;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	res = 1;
	buflst = NULL;
	final_str = NULL;
	while (res > 0)
	{
		i = 0;
		while (i < BUFFER_SIZE)
		{
			res = read(fd, buf + i, 1);
			if (buf[i] == '\n')
				break ;
			i++;
		}
		ft_lstadd_back(&buflst, ft_strlstnew(buf));
		if (buf[i] == '\n')
			break ;
		ft_bzero(buf, BUFFER_SIZE);
	}
	if (*buf)
		final_str = ft_merge_strlst(buflst);
	free(buf);
	ft_lstclear(&buflst, &free);
	return (final_str);
}
