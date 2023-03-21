/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:15 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/21 14:54:21 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;
	size_t	i;

	mem = malloc(nmemb * size);
	i = size * nmemb;
	while (i)
		mem[--i] = 0;
	return (mem);
}

void	*ft_bzero(void *s, size_t n)
{
	const void	*ptr;

	ptr = s;
	while (n--)
		*(unsigned char *)(s++) = 0;
	return ((void *) ptr);
}

size_t	ft_lstsize(t_list *lst)
{
	size_t	c;

	if (!lst)
		return (0);
	c = 1;
	if (lst->next)
		c = ft_lstsize(lst->next) + 1;
	return (c);
}

t_list	*ft_strlstnew(char *content)
{
	t_list			*node;
	size_t			i;
	unsigned char	filled;

	node = malloc(sizeof(t_list));
	i = 0;
	filled = 0;
	if (!node)
		return (NULL);
	node->content = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (i < BUFFER_SIZE)
	{
		((char *) node->content)[i] = content[i];
		if (((char *) node->content)[i])
			filled = 1;
		i++;
	}
	node->next = NULL;
	if (!filled)
	{
		ft_lstclear(&node, &free);
		node = NULL;
	}
	return (node);
}

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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst || !*lst || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear(&((*lst)->next), del);
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}

char	*ft_merge_strlst(t_list *lst)
{
	char	*str;
	size_t	i;
	size_t	j;

	// FIXME malloc only necessary chars
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
