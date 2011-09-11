#include "core.h"
#include <stddef.h>

typedef struct domain_ domain;

struct domain_ {
};

void *
domain_malloc(domain *domain, size_t size);

void
domain_free(domain *domain, void *ptr);

/*address
domain_register(domain *domain, actor *actor);

void
unregister(domain *domain, actor *actor);*/
