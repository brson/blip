#include "domain.h"
#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

const int max_actors = 10;
const int max_messages = 10;

struct domain_ {
  actor *actors[max_actors];
  message next_msg;
};

domain *
domain_new() {
  domain *dom = (domain *) malloc(sizeof(domain));
  memset(dom, 0, sizeof(domain));
  return dom;
}

void
domain_delete(domain *domain) {
  assert(domain != 0);
  free(domain);
}

void *
domain_malloc(domain *domain, size_t size) {
  return malloc(size);
}

void
domain_free(domain *domain, void *ptr) {
  free(ptr);
}

address
domain_register_actor(domain *domain, actor *actor) {
  assert(domain != 0);

  domain->actors[0] = actor;
  address address = {
    .dom_id = 1,
    .actor_id = 1
  };
  return address;
}

void
domain_unregister_actor(domain *domain, actor *actor) {
  assert(domain != 0);
  domain->actors[0] = 0;
}

void
domain_send_message(domain *domain, actor *self,
		    address dest, address value) {
  message msg = {
    .sender = {
      .dom_id = 1,
      .actor_id = 1
    },
    .value = value
  };
  domain->next_msg = msg;
}

void
domain_join(domain *domain) {
  assert(domain != 0);
  if (domain->actors[0]) {
    actor *actor = domain->actors[0];
    facet *facet = actor->current_facet;
    facet->selectors[0].handler(domain, actor, domain->next_msg);
  }
}
