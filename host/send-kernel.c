#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

static void write_or_abort(int fd, uint8_t byte) {
	if (write(fd, &byte, 1) != 1) {
		perror("write");
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s DEVICE IMAGE\n", argv[0]);
		return EXIT_FAILURE;
	}
	int dstfd = open(argv[1], O_WRONLY);
	if (dstfd < 0) {
		perror("Cannot open DEVICE");
		return EXIT_FAILURE;
	}
	int srcfd = open(argv[2], O_RDONLY);
	if (srcfd < 0) {
		perror("Cannot open IMAGE");
		return EXIT_FAILURE;
	}
	struct stat stat;
	if (fstat(srcfd, &stat) < 0) {
		perror("Cannot stat IMAGE");
		return EXIT_FAILURE;
	}
	write_or_abort(dstfd, (stat.st_size >> 24) & 0xff);
	write_or_abort(dstfd, (stat.st_size >> 16) & 0xff);
	write_or_abort(dstfd, (stat.st_size >> 8) & 0xff);
	write_or_abort(dstfd, stat.st_size & 0xff);
	while (stat.st_size--) {
		uint8_t byte;
		if (read(srcfd, &byte, 1) != 1) {
			perror("read");
			return EXIT_FAILURE;
		}
		write_or_abort(dstfd, byte);
	}
	return EXIT_SUCCESS;
}