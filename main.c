/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:21:00 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/04 22:01:27 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>

int main() {
	int fildes = open("test.txt", O_RDONLY);
	void *buf;
	size_t nbytes;
	char *line;
	int i;

	// first, try reading from file
	line = get_next_line(fildes);
	while (line) {
		printf("Linea %i: %s", i++, line);
		line = get_next_line(fildes);
	}

	// try reading from stdio
	line = get_next_line(0);
	printf("stdin: %s", line);
	return 0;
}
