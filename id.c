#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
	uid_t euid;
	uid_t uid;
	uid_t egid;
	uid_t gid;
	int i;

	euid = geteuid();
	uid = getuid();
	egid = getegid();
	gid = getgid();
	fprintf(stderr, "euid: %d uid: %d egid: %d gid: %d\n", euid, uid, egid, gid);
	fprintf(stderr, "arg count %d\n", argc);
	for (i = 0; i < argc; i++) {
		fprintf(stderr, "%d : %s\n", i, argv[i]);
	}
	return 0;
}
