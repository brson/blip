#include <stddef.h>
#include "a_core.h"

typedef ac_address (*ak_package_init)();

ac_address
ak_load_package(char *name);

ac_domain *
ak_create_domain();

uintptr_t
ak_malloc(ac_domain *domain, size_t size);

void
ak_free(ac_domain *domain, uintptr_t ptr);

ac_address
ak_register(ac_domain *domain, ac_actor *actor);

void
ak_unregister(ac_domain *domain, ac_actor *actor);
