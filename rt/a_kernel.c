#include <stdlib.h>
#include "a_core.h"

typedef struct ak_kernel_ ak_kernel;

ac_address
ak_load_package(char *name) {
  abort();
}

ac_domain *
ak_create_domain() {
  abort();
}

uintptr_t
ak_malloc(ac_domain *domain, size_t size) {
  abort();
}

void
ak_free(ac_domain *domain, uintptr_t ptr) {
  abort();
}

ac_address
ak_register(ac_domain *domain, ac_actor *actor) {
  abort();
}

void
ak_unregister(ac_domain *domain, ac_actor *actor) {
  abort();
}
