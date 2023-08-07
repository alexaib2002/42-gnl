/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:13:46 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/24 11:24:14 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
