#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>


int main() {
	int fd;
	fd = open("/Users/zech-chi/Desktop/get_next_line/testfiles/file.txt", O_RDONLY);
	static char buff[0];
	printf("%d\n", fd);
	int r = read(fd, buff, 5);
	printf("%s\n", buff);
	printf("%d\n", r);
	return (0);
}