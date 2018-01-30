#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "words-cheat.h"

int main(int argc, char **argv) {
	if (!validate_invocation(argc, argv)) {
		printf("ERROR: use invocation [binary] [character list] [minimum characters] [keep/throw]\n");
		exit(EXIT_FAILURE);
	}
	char *chars = argv[1], *strategy = argv[3], line[256], *pos;
	bool throw = (strcmp("throw", strategy) == 0);
	int min_chars = atoi(argv[2]);
	FILE *f = fopen("/usr/share/dict/words", "r");
	if (f == NULL) exit(EXIT_FAILURE);
	while(fgets(line, 256, f)) {
		if ((pos=strchr(line, '\n')) != NULL) *pos = '\0';
		if (is_possible(line, chars, min_chars, throw)) printf("%s\n", line);
	}
	fclose(f);
	exit(EXIT_SUCCESS);
}
