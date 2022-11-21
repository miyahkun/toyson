#include <stdio.h>

#define done() return 0
#define fail() return __LINE__
static int checkqty = 0;

#define check(x) \
  do {           \
    ++checkqty;  \
    if (!(x)) {  \
      fail();    \
    }            \
  } while (0)

struct test {
  int (*func)(void);
  char const* name;
};

static int test_suit(struct test const* tests, int num_tests) {
  printf("%s", "\n\nTests:\n");
  int failed = 0;
  for (int i = 0; i < num_tests; ++i) {
    printf("%02d%s%ds ", i, ": ", i);
    int result = tests[i].func();
    if (0 == result) {
      printf("%s", "OK\n");
    } else {
      printf("%s%d\n", "Failed, line: ", result);
      ++failed;
    }
  }
  printf("\n%s%d\n", "Total checks: ", checkqty);
  printf("%s[ %d / %d ]\n\n\n", "Tests PASS: ", num_tests - failed, num_tests);
  printf("\n");
  return failed;
}

static int empty(void) {
  check(0);
  return 0;
}

int main(void) {
  static struct test const tests[] = {
      {empty, "Empty object and array"},
  };

  test_suit(tests, sizeof tests / sizeof *tests);
  return 0;
}
