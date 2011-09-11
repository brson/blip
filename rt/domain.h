#ifndef _RT_DOMAIN_H_
#define _RT_DOMAIN_H_

#include <stddef.h>

typedef struct domain_ domain;

void *
domain_malloc(domain *domain, size_t size);

void
domain_free(domain *domain, void *ptr);

/*address
domain_register(domain *domain, actor *actor);

void
unregister(domain *domain, actor *actor);*/

#endif // _RT_DOMAIN_H_
