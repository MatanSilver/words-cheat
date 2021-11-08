# words-cheat

words-cheat is a simple C program to find all words possible from a character set. It works by searching through the wordlist file in macOS, located at `/usr/share/dict/words`. For testing, words-cheat uses a very simple, hand-written test framework supporting simple expression assertions.

# Usage
To use words-cheat, call:
```bash
words-cheat [character list] [minimum characters] [keep/throw]
```

"character list" is the list of characters that can be used to construct a word. "minimum characters" is an integer number representing a minimum number of characters the word matches must be. "keep" will remove only allow a character to appear as many times in a word as it does in the character list. "throw" will allow for character repetition. 