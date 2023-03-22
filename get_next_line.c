/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:10 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/22 18:56:39 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (new)
	{
		if (*lst)
		{
			while ((*lst)->next)
				lst = &((*lst)->next);
			(*lst)->next = new;
		}
		else
			*lst = new;
	}
}

char	*ft_merge_strlst(t_list *lst)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!lst)
		return (NULL);
	str = ft_calloc((ft_lstsize(lst) * BUFFER_SIZE) + 1, sizeof(char));
	i = 0;
	while (lst && *((unsigned char *) lst->content))
	{
		j = 0;
		while (j < BUFFER_SIZE && ((unsigned char *) lst->content)[j])
		{
			str[i++] = ((unsigned char *) lst->content)[j++];
			if (((unsigned char *) lst->content)[j - 1] == '\n')
				break ;
		}
		lst = lst->next;
	}
	return (str);
}

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

ssize_t	unreliable_read(int __fd, void *__buf, size_t __nbytes)
{
	if (!fails)
		return read(__fd, __buf, __nbytes);
	fails = 0;
	return -1;
}

static size_t	read_next_line(int fd, char *buf, t_list **buflst)
{
	size_t	i;
	ssize_t	res;

	res = 1;
	while (res > 0)
	{
		i = 0;
		if (!buf[i])
			res = unreliable_read(fd, buf, BUFFER_SIZE);
		while (i < BUFFER_SIZE && buf[i] && buf[i] != '\n')
			i++;
		ft_lstadd_back(buflst, ft_strlstnew(buf));
		if (buf[i] == '\n')
			break ;
		ft_bzero(buf, BUFFER_SIZE);
	}
	return (res);
}


char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*final_str;
	t_list		*buflst;
	ssize_t		res;

	buflst = NULL;
	final_str = NULL;
	if (buf == NULL)
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	res = read_next_line(fd, buf, &buflst);
	if ((*buf || ft_lstsize(buflst) > 0) && res >= 0)
		final_str = ft_merge_strlst(buflst);
	if (res <= 0)
	{
		free(buf);
		buf = NULL;
	}
	else
		mov_buf(buf);
	ft_lstclear(&buflst, &free);
	return (final_str);
}
