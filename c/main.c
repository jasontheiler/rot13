#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rot13(char* buf, int n) {
	char a;
	for (size_t i = 0; i < n; i++) {
		if (buf[i] >= 'a' && buf[i] <= 'z') {
			a = 'a';
		} else if (buf[i] >= 'A' && buf[i] <= 'Z') {
			a = 'A';
		} else {
			continue;
		}
		buf[i] = ((buf[i] - a + 13) % 26) + a;
	}
}

int from_args(int argc, char** argv) {
	for (size_t i = 1; i < argc; i++) {
		rot13(argv[i], strlen(argv[i]));
		if (fputs(argv[i], stdout) == EOF) {
			return EXIT_FAILURE;
		}
		char* c;
		if (i < argc - 1) {
			c = " ";
		} else {
			c = "\n";
		}
		if (fputs(c, stdout) == EOF) {
			return EXIT_FAILURE;
		}
	}
	return EXIT_SUCCESS;
}

int from_stdin() {
	char buf[128];
	while (true) {
		if (fgets(buf, sizeof(buf), stdin) == NULL) {
			break;
		}
		rot13(buf, strlen(buf));
		if (fputs(buf, stdout) == EOF) {
			return EXIT_FAILURE;
		};
	}
	if (!feof(stdin)) {
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

int main(int argc, char** argv) {
	if (argc > 1) {
		return from_args(argc, argv);
	}
	return from_stdin();
}
