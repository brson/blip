#include "kernel.h"
#include <stdint.h>
#include <assert.h>

void
new_domain_ctor(domain *domain) {
  actor *a = (actor*) domain_malloc(domain, sizeof(actor));
  address address = domain_register_actor(domain, a);
  assert(address.dom_id != 0);
  assert(address.actor_id != 0);
  domain_unregister_actor(domain, a);
  domain_free(domain, a);
}

int
main() {
  kernel *kernel = kernel_start();
  kernel_new_domain(kernel, new_domain_ctor);
  kernel_join(kernel);
}
