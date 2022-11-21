#include <stdbool.h>

static char const *const blank = " \n\r\t\f";

bool isOneOfThem(char ch, char const *set) {
  while (*set != '\0') {
    if (ch == *set++) {
      return true;
    }
  }
  return false;
}

char *goWhile(char *str, const char *set) {
  for (; *str != '\0'; ++str) {
    if (!isOneOfThem(*str, set)) {
      return str;
    }
  }
  return 0;
}

static char *goBlank(char *str) { return goWhile(str, blank); }

int toyson_create(void) { return 0; }
