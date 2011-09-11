#include "kernel.h"
#include "domain.h"

void
new_domain_cb(ac_domain *domain) {
  uintptr_t *p = (uintptr_t*) ad_malloc(domain, sizeof(uintptr_t));
  *p = 100;
  ad_free(domain, p);
}

int
main() {
  ak_kernel *kernel = ak_start();
  ak_new_domain(new_domain_cb);
  ak_join(kernel);
}
