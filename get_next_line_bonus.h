/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:14:11 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/24 11:26:15 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# ifndef MAX_FD
#  define MAX_FD 65536
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*******************
* Type declarations
*****************/

/**
 * @struct s_list
 * @brief Represents a node on a list. Will have a reference to its content and
 * a reference to the next item, the latter being NULL when the end is reached.
 * @var s_list::content
 * References the data stored in this node
 * @var s_list::content
 * References the next node, will be NULL on the last node
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);

/********
 * Utils
******/
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_bzero(void *s, size_t n);

/**
 * @brief Copies the 'content' string into a new node's content.
 * Serves as replacement for calling both memcpy and lstnew
 * @param content Origin string
 * @return Node created
 */
t_list	*ft_strlstnew(char *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
size_t	ft_lstsize(t_list *lst);
char	*ft_merge_strlst(t_list *lst);

#endif
