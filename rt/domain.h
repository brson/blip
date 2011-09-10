#include "kernel.h"

uintptr_t
ad_malloc(ac_domain *domain, size_t size);

void
ad_free(ac_domain *domain, uintptr_t ptr);

ac_address
ad_register(ac_domain *domain, ac_actor *actor);

void
ad_unregister(ac_domain *domain, ac_actor *actor);
