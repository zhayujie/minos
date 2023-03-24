#include "user.h"

void printf(char * st) {
  int i;

  for (i = 0; st[i]; i++) {
    write(st[i]);
  }
}
