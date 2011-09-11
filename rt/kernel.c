#include "kernel.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

domain *
domain_new();

void
domain_delete(domain *domain);

void
domain_join(domain *domain);

struct kernel_ {
  domain *domains[10];
};

kernel *
kernel_start() {
  kernel *k = (kernel *) malloc(sizeof(kernel));
  memset(k, 0, sizeof(kernel));
  return k;
}

void
kernel_new_domain(kernel *kernel, domain_ctor ctor) {
  assert(kernel != 0);
  assert(ctor != 0);
  kernel->domains[0] = domain_new();
  ctor(kernel->domains[0]);
}

int
kernel_join(kernel *kernel) {
  assert(kernel != 0);
  for (int i = 0; i < 10; i++) {
    if (kernel->domains[i] != 0) {
      domain_join(kernel->domains[i]);
      domain_delete(kernel->domains[i]);
    }
  }
  free(kernel);
  return 0;
}
