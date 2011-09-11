#ifndef _RT_CORE_H_
#define _RT_CORE_H_

/*#include <stdint.h>

typedef uintptr_t ac_dom_id;
typedef uintptr_t ac_actor_id;
typedef struct ac_address_ ac_address;
typedef struct ac_message_ ac_message;
typedef struct actor_ actor;
typedef struct ac_selector_ ac_selector;
typedef struct ac_facet_ ac_facet;
typedef void (*ac_handler)(ac_domain *, actor *, ac_message *);

extern const ac_dom_id invalid_dom_id;
extern const ac_actor_id invalid_actor_id;

struct ac_address_ {
  ac_dom_id dom_id;
  ac_actor_id actor_id;
};

struct ac_message_ {
  ac_address sender;
  ac_address value;
};

struct ac_selector_ {
  ac_address sender;
  ac_address value;
  ac_handler *handler;
};

struct ac_facet_ {
  uintptr_t num_selectors;
  ac_selector *selectors;
  uintptr_t data[];
};

struct actor_ {
  ac_facet *current_facet;
  uintptr_t num_elements;
  ac_address *elements;
  uintptr_t data[];
};
*/
#endif // _RT_CORE_H_
