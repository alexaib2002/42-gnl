/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:04:15 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/05 12:50:12 by aaibar-h         ###   ########.fr       */
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

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next)
		return (ft_lstlast(lst->next));
	else
		return (lst);
}

static void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

static size_t	ft_lstsize(t_list *lst)
{
	int	c;

	if (!lst)
		return (0);
	c = 1;
	if (lst->next)
		c = ft_lstsize(lst->next) + 1;
	return (c);
}

t_list	*ft_strlstnew(char *content)
{
	t_list	*node;
	size_t	i;

	node = malloc(sizeof(t_list));
	i = 0;
	if (!node)
		return (NULL);
	node->content = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (i < BUFFER_SIZE)
	{
		((char *) node->content)[i] = content[i];
		i++;
	}
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (new)
	{
		if (*lst)
			ft_lstlast(*lst)->next = new;
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
	ft_lstdelone(*lst, del);
	*lst = NULL;
}

char	*ft_merge_strlst(t_list *lst)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = ft_calloc(ft_lstsize(lst) * BUFFER_SIZE, sizeof(char));
	i = 0;
	while (lst && *((unsigned char *) lst->content))
	{
		j = 0;
		while (j < BUFFER_SIZE)
			str[i++] = ((unsigned char *) lst->content)[j++];
		lst = lst->next;
	}
	return (str);
}
