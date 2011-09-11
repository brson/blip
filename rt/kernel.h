#include "core.h"
#include <stddef.h>

typedef ac_address (*ak_package_init)();

typedef struct ak_kernel_ ak_kernel;

typedef void (*ak_new_domain_cb)(ac_domain *domain);

ak_kernel *
ak_start();

int
ak_join(ak_kernel *kernel);

void
ak_new_domain(ak_new_domain_cb new_domain_cb);
