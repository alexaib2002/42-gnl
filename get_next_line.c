/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/21 14:40:09 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	mov_buf(char *buf)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < BUFFER_SIZE)
	{
		if (i > 0 && buf[i - 1] == '\n')
			break ;
		i++;
	}
	while (buf[i])
		buf[j++] = buf[i++];
	while (buf[j])
		buf[j++] = 0;
}


char	*get_next_line(int fd)
{
	static char	*buf = NULL;
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
		if (!buf[i])
			res = read(fd, buf, BUFFER_SIZE);
		while (i < BUFFER_SIZE && buf[i] && buf[i] != '\n')
			i++;
		ft_lstadd_back(&buflst, ft_strlstnew(buf));
		if (buf[i] == '\n')
			break ;
		ft_bzero(buf, BUFFER_SIZE);
	}
	if (*buf || ft_lstsize(buflst) > 0)
		final_str = ft_merge_strlst(buflst);
	if (!res)
	{
		free(buf);
		buf = NULL;
	}
	else
		mov_buf(buf);
	ft_lstclear(&buflst, &free);
	return (final_str);
}
