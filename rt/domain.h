#ifndef _RT_DOMAIN_H_
#define _RT_DOMAIN_H_

#include "core.h"
#include <stddef.h>

void *
domain_malloc(domain *domain, size_t size);

void
domain_free(domain *domain, void *ptr);

address
domain_register_actor(domain *domain, actor *actor);

void
domain_unregister_actor(domain *domain, actor *actor);

void
domain_send_message(domain *domain, actor *self,
		    address dest, address value);

#endif // _RT_DOMAIN_H_
