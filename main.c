#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>	
#include <string.h>


int main() {
	char *s1 = ft_strdup("kossa");
	char *s2 = ft_strdup("ysso");
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}