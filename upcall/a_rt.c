#include<stdint.h>

typedef struct package_ package;
typedef uintptr_t proto_id;
typedef struct mailbox_ mailbox;
typedef package *(*package_loader)();

struct package_ {
  uintptr_t num_protos;
  proto_id *proto_table;
  uintptr_t data[];
};


const proto_id invalid_proto_id = 0;

const address init_address = {
  .dom_id = 1,
  .actor_id = 1
};

address *
upcall_create(domain *home, proto_id proto_id) {
  return 0;
}

void
upcall_die(domain *home, actor *self) {
}

void
upcall_send_message(domain *home, address *address, message *message) {
}
