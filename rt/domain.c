#include "domain.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>

struct domain_ {
};

domain *
domain_new() {
  return (domain *) malloc(sizeof(domain));
}

void
domain_delete(domain *domain) {
  assert(domain != 0);
  free(domain);
}

void *
domain_malloc(domain *domain, size_t size) {
  return malloc(size);
}

void
domain_free(domain *domain, void *ptr) {
  free(ptr);
}

/*ac_address
ad_register(ac_domain *domain, ac_actor *actor);

void
ad_unregister(ac_domain *domain, ac_actor *actor);*/
