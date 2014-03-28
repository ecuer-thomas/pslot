#include <stdio.h>
#include <time.h>

#include <unistd.h>
#include <sys/syscall.h>

int main(int ac, char **av)
{
	time_t t = time(0);
	printf("%s", ctime(&t));

	printf("-----------------------------------------------\n");
	syscall(314, 0, 0);
	return 0;
}
