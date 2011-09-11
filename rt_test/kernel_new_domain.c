#include "kernel.h"
#include <assert.h>
#include <stdbool.h>

bool created = false;

void
new_domain_cb(ac_domain *domain) {
  assert(domain != 0);
  created = true;
}

int
main() {
  ak_kernel *kernel = ak_start();
  ak_new_domain(new_domain_cb);
  ak_join(kernel);
  assert(created == true);
}
