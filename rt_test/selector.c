#include "kernel.h"
#include <stdint.h>
#include <assert.h>

typedef struct testactor_ {
  actor header;
  address empty_selector_address;
  facet facet;
  selector selector;
} testactor;

const address test_message = {
  .dom_id = 100,
  .actor_id = 101
};

address g_source_address;
domain *g_domain;

void
test_handler(domain *domain, actor *self, message msg) {
  assert(g_domain == domain);

  assert(g_source_address.dom_id == msg.sender.dom_id);
  assert(g_source_address.actor_id == msg.sender.actor_id);
  assert(test_message.dom_id == msg.value.dom_id);
  assert(test_message.actor_id == msg.value.actor_id);

  testactor *a = (testactor*) self;
  assert(a->selector.handler == test_handler);

  domain_unregister_actor(domain, self);
  domain_free(domain, self);
}

void
new_domain_ctor(domain *domain) {
  g_domain = domain;

  testactor *a = (testactor*) domain_malloc(domain, sizeof(testactor));

  a->header.current_facet = &a->facet;
  a->empty_selector_address = empty_selector_address;

  a->facet.num_selectors = 1;
  a->facet.selectors = &a->selector;

  a->selector.sender = &a->empty_selector_address;
  a->selector.value = &a->empty_selector_address;
  a->selector.handler = test_handler;

  g_source_address = domain_register_actor(domain, &a->header);

  domain_send_message(domain, &a->header, g_source_address, test_message);
}

int
main() {
  kernel *kernel = kernel_start();
  kernel_new_domain(kernel, new_domain_ctor);
  kernel_join(kernel);
}
