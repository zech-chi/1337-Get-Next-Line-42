#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	


int main() {

	int fd = open("test.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 7; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}