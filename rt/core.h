#ifndef _RT_CORE_H_
#define _RT_CORE_H_

#include <stdint.h>

typedef uintptr_t dom_id;
typedef uintptr_t actor_id;
typedef struct domain_ domain;
typedef struct address_ address;
typedef struct message_ message;
typedef struct actor_ actor;
typedef struct selector_ selector;
typedef struct facet_ facet;
typedef void (*msg_handler)(domain *, actor *, message *);

extern const dom_id invalid_dom_id;
extern const actor_id invalid_actor_id;

struct address_ {
  dom_id dom_id;
  actor_id actor_id;
};

struct message_ {
  address sender;
  address value;
};

struct selector_ {
  address sender;
  address value;
  msg_handler *handler;
};

struct facet_ {
  uintptr_t num_selectors;
  selector *selectors;
  uintptr_t data[];
};

struct actor_ {
  facet *current_facet;
  uintptr_t num_elements;
  address *elements;
  uintptr_t data[];
};

#endif // _RT_CORE_H_
