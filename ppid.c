#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t ppid = getppid();

	printf("The PID of the parent process is %d\n", ppid);

	return 0;
}
