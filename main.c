#include <stdbool.h>
#include <stdio.h>

#include "identify.h"
#include "version_info.h"

static char const *const dlm = ".........."
                               ".........."
                               ".........."
                               ".........."
                               ".........."
                               "..........";

/*
 *  MARK: A()
 */
bool A(bool a) {
  printf("- %s(.%c.) ", __func__, (a ? 'T' : 'F'));
  return a;
}

/*
 *  MARK: B()
 */
bool B(bool b) {
  printf("- %s(.%c.) ", __func__, (b ? 'T' : 'F'));
  return b;
}

/*
 *  MARK: C()
 */
bool C(bool c) {
  printf("- %s(.%c.) ", __func__, (c ? 'T' : 'F'));
  return c;
}

/*
 *  MARK: ors()
 */
void ors(size_t ix, bool a, bool b, bool c) {
  printf("%3zu: .%c. || .%c. || .%c. : ",
         ix,
         (a ? 'T' : 'F'), (b ? 'T' : 'F'),
         (c ? 'T' : 'F'));
  if (A(a) || B(b) || C(c)) {
    printf(" : success");
  }
  else {
    printf(" : fail");
  }
  putchar('\n');
  return;
}

/*
 *  MARK: ands()
 */
void ands(size_t ix, bool a, bool b, bool c) {
  printf("%3zu: .%c. && .%c. && .%c. : ",
         ix,
         (a ? 'T' : 'F'), (b ? 'T' : 'F'),
         (c ? 'T' : 'F'));
  if (A(a) && B(b) && C(c)) {
    printf(" : success");
  }
  else {
    printf(" : fail");
  }
  putchar('\n');
  return;
}

/*
 *  MARK: main()
 */
int main(int argc, char const *argv[]) {
  puts(dlm);
  identify();
  putchar('\n');

  puts(dlm);
  version_details();

  puts(dlm);
  size_t ix = 0;
  ors(ix++, true, true, true);
  ors(ix++, false, true, true);
  ors(ix++, false, false, true);
  ors(ix++, false, false, false);

  ands(ix++, true, true, true);
  ands(ix++, true, true, false);
  ands(ix++, true, false, false);
  ands(ix++, false, false, false);

  return 0;
}
