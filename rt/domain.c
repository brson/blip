#include "core.h"
#include <stddef.h>
#include <stdlib.h>

void *
ad_malloc(ac_domain *domain, size_t size) {
  return malloc(size);
}

void
ad_free(ac_domain *domain, void *ptr) {
  free(ptr);
}

ac_address
ad_register(ac_domain *domain, ac_actor *actor);

void
ad_unregister(ac_domain *domain, ac_actor *actor);
