#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <errno.h>

int main(int argc, char *argv[]) {
	int res;
	int vallen;
	if (argc != 4) {
		fprintf(stderr, "usage setxattr file attribute value");
	}
	vallen = strlen(argv[3]);
	res = setxattr(argv[1], argv[2], argv[3], vallen, XATTR_CREATE);
	if (res) {
		fprintf(stdout, "Error for XATTR_CREATE: %s\n", strerror(errno));
		fprintf(stdout, "Trying XATTR_REPLACE\n");
		res = setxattr(argv[1], argv[2], argv[3], vallen, XATTR_CREATE);
		if (res) {
			fprintf(stderr, "Error for XATTR_REPLACE: %s\n", strerror(errno));
			return 1;
		}
	}
	fprintf(stdout, "result: %d (0 is success)\n", res);
	fprintf(stdout, "strerror(errno): %s\n", strerror(errno));
	return 0;
}
