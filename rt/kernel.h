#include "core.h"
#include <stddef.h>

typedef ac_address (*ak_package_init)();

typedef struct ak_kernel_ ak_kernel;

ak_kernel *
ak_start();

int
ak_join(ak_kernel *kernel);

ac_address
ak_load_package(char *name);

