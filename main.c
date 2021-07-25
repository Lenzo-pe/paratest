# include <fcntl.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include <stdio.h>

void	putstr(char *str)
{
	while (*str)
	{
		write(1, &(*str), 1);
		str++;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	int fd[2];
	char *str;

	fd[0] = open("d.txt", O_RDWR);
	fd[1] = open("a.txt", O_RDWR);
	while (str)
	{
		str = get_next_line(fd[0]);
		printf("%s", str);
		free(str);
		str = get_next_line(fd[1]);
		printf("%s", str);
		free(str);
	}
	close(fd[0]);
	close(fd[1]);
	return (0);
}