#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int strchrcnt(const char *haystack, const char needle) {
	int count = 0;
	char *pos;
		while((pos = strchr(haystack, needle)) != NULL && strlen(haystack) > 0) {
			count++, haystack = pos + 1;
	}
	return count;
}

bool is_possible(char *word, char *chars, size_t minimum) {
	size_t wordlen = strlen(word);
	int wordcnt, charscnt;
	for (size_t i = 0; i < wordlen; i++) {
		if (wordlen < minimum) return false;
		charscnt = strchrcnt(chars, word[i]);
		wordcnt = strchrcnt(word, word[i]);
		if (wordcnt > charscnt) return false;
	}
	return true;
}

int main(int argc, char **argv) {
	char *chars = argv[1], line[256], *pos;
	int min_chars = atoi(argv[2]);
	FILE *f = fopen("/usr/share/dict/words", "r");
	if (f == NULL) exit(EXIT_FAILURE);
	while(fgets(line, 256, f)) {
		if ((pos=strchr(line, '\n')) != NULL) *pos = '\0';
		if (is_possible(line, chars, min_chars)) printf("%s\n", line);
	}
	fclose(f);
	exit(EXIT_SUCCESS);
}
