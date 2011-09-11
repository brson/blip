#include "kernel.h"
#include <stdlib.h>
#include <assert.h>

struct kernel_ {
  int i;
};

kernel *
kernel_start() {
  kernel *k = (kernel *) malloc(sizeof(kernel));
  return k;
}

int
kernel_join(kernel *kernel) {
  free(kernel);
  return 0;
}

void
kernel_new_domain(domain_ctor ctor) {
  assert(ctor != 0);
  domain domain;
  ctor(&domain);
}
