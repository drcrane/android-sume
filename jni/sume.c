#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	uid_t myeuid;
	uid_t newuid;
	int res;
	int fd;

	//fd = open("/data/local/tmp/sume.was", O_CREAT);
	//close(fd);

	myeuid = geteuid();
	fprintf(stdout, "switching to uid %d\n", myeuid);
	setuid(myeuid);
	newuid = getuid();
	if (newuid != myeuid) {
		fprintf(stderr, "setuid() failed to work\n");
		return 1;
	}
	if (argc <= 1) {
		fprintf(stderr, "please provide at least one argument\n");
		return 1;
	}
	res = execv(argv[1], &argv[1]);
	fprintf(stderr, "Failed to execute %s\n", argv[1]);
	return 0;
}

