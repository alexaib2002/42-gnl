/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:21:00 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/04 17:59:50 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
	int fildes = open("test.txt", O_RDONLY);
	void *buf;
	size_t nbytes;
	char *line;
	int i;

	line = get_next_line(fildes);
	while (line) {
		printf("Linea %i: %s", i++, line);
		line = get_next_line(fildes);
	}
	return 0;
}
