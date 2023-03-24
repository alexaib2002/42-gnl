/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaibar-h <aaibar-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:21:00 by aaibar-h          #+#    #+#             */
/*   Updated: 2023/03/24 09:50:36 by aaibar-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdio.h>

static void read_file_fildes(const int fildes) {
	char	*line;
	int		i;
	
	printf("\n==Starting file read==\n");
	line = get_next_line(fildes);
	i = 1;
	while (line) {
		printf("Linea %i: %s", i++, line);
		free(line);
		line = get_next_line(fildes);
	}
	if (line)
		free(line);
	printf("\n==Reached EOF==\n");
}

static void read_file_gnl(const char *file_name) {
	read_file_fildes(open(file_name, O_RDONLY));
}

static void stdio_gnl() {
	// try reading from stdio
	char *line = get_next_line(0);
	printf("stdin: %s", line);
	free(line);
}

static void read_conc_gnl() {
	int fds[3];
	fds[0] = open("file1.txt", O_RDONLY);
	fds[1] = open("file2.txt", O_RDONLY);
	fds[2] = open("file3.txt", O_RDONLY);
	char *line = "";
	while (line) {
		int i = 0;
		while (i < 3) {
			line = get_next_line(fds[i++]);
			if (line) {
				printf("%i: %s", i, line);
				free(line);
			}
		}
		printf("\n");
	}
}

int main() {
	read_conc_gnl();
	printf("... Testing %s ...\n", "Read from generic file");
	read_file_gnl("test.txt");	// Test for generic file
	printf("... Testing %s ...\n", "Read from stdio descriptor");
	stdio_gnl();				// Test for stdio fildes
	printf("... Testing %s ...\n", "Read from empty file");
	read_file_gnl("empty.txt");	// Test for empty file
	printf("... Testing %s ...\n", "Read from invalid file descriptor");
	read_file_fildes(11037);	// Test for invalid fildes
	return 0;
}
