#include "kernel.h"
#include <assert.h>

int
main() {
  ak_kernel *kernel = ak_start();
  int res = ak_join(kernel);
  assert(res == 0);
}
