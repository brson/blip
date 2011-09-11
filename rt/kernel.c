#include "kernel.h"
#include <stdlib.h>
#include <assert.h>

struct ak_kernel_ {
  int i;
};

ak_kernel *
ak_start() {
  ak_kernel *kernel = (ak_kernel*) malloc(sizeof(ak_kernel));
  return kernel;
}

int
ak_join(ak_kernel *kernel) {
  free(kernel);
  return 0;
}

void
ak_new_domain(ak_new_domain_cb new_domain_cb) {
  assert(new_domain_cb != 0);
  ac_domain domain;
  new_domain_cb(&domain);
}
