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
	int wordcnt, charscnt;
	for (size_t i = 0; i < wordlen; i++) {
		if (wordlen < minimum) return false;
		charscnt = strchrcnt(chars, word[i]);
		wordcnt = strchrcnt(word, word[i]);
		if (throw && wordcnt > charscnt) return false;
		else if (charscnt == 0) return false;
	}
	return true;
}
