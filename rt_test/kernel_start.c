#include "kernel.h"
#include <assert.h>

int
main() {
  kernel *kernel = kernel_start();
  int res = kernel_join(kernel);
  assert(res == 0);
}
