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

bool is_possible(char *word, char *chars, size_t minimum, bool throw) {
	size_t wordlen = strlen(word);
	if (wordlen < minimum) return false;
	int wordcnt, charscnt;
	for (size_t i = 0; i < wordlen; i++) {
		charscnt = strchrcnt(chars, word[i]);
		wordcnt = strchrcnt(word, word[i]);
		if (throw && wordcnt > charscnt) return false;
		else if (charscnt == 0) return false;
	}
	return true;
}

bool validate_invocation(int argc, char ** argv) {
	if (argc != 4) {
		return false;
	}
	for (size_t i = 0; i < strlen(argv[2]); i++) {
		if ((argv[2][i] < 48) || (argv[2][i] > 57)) {
			return false;
		}
	}
	if (strcmp(argv[3], "throw") != 0 && strcmp(argv[3], "keep") != 0) {
		return false;
	}
	return true;
}
