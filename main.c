#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
	int	fd1;
	int fd2;
	int i = 5;
	char	*line1;
	char	*line2;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);

	while(i--)
	{
		line1 = get_next_line(fd1);
		printf("%s", line1);
		line2 = get_next_line(fd2);
		printf("%s", line2);
	}
	close(fd1);
	close(fd2);
}
