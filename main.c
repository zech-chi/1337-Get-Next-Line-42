#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>


int main() {
	int fd = open("/Users/zech-chi/Desktop/get_next_line/testfiles/file.txt", O_RDONLY);
	char	*line;
	for (int i = 0; i < 1; i++)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
	}
	return (0);
}