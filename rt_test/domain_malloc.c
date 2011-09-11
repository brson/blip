#include "kernel.h"
#include <stdint.h>

void
new_domain_ctor(domain *domain) {
  uintptr_t *p = (uintptr_t*) domain_malloc(domain, sizeof(uintptr_t));
  *p = 100;
  domain_free(domain, p);
}

int
main() {
  kernel *kernel = kernel_start();
  kernel_new_domain(kernel, new_domain_ctor);
  kernel_join(kernel);
}
