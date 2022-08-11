#ifndef _REGEX_H_
#define _REGEX_H_

int regex_match(char const *str, char const *pattern);
int match_here(char const *regexp, char const *text);
int matchstar(int c, char const *regexp, char const *text);

#endif /*_REGEX_H_*/
