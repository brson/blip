#include "domain.h"

typedef struct kernel_ kernel;

typedef void (*domain_ctor)(domain *);

kernel *
kernel_start();

int
kernel_join(kernel *kernel);

void
kernel_new_domain(domain_ctor);
