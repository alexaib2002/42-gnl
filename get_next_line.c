/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/05 11:33:28 by aaibar-h         ###   ########.fr       */
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

	buf = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	res = 1;
	buflst = NULL;
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
	if (!*buf)
		return (NULL);
	final_str = ft_merge_strlst(buflst);
	ft_lstclear(&buflst, &free);
	return (final_str);
}
