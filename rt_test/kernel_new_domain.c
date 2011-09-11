#include "kernel.h"
#include <assert.h>
#include <stdbool.h>

bool created = false;

void
new_domain_ctor(domain *domain) {
  assert(domain != 0);
  created = true;
}

int
main() {
  kernel *kernel = kernel_start();
  kernel_new_domain(new_domain_ctor);
  kernel_join(kernel);
  assert(created == true);
}
