#include "kernel.h"
#include <stdio.h>

int
main(int argc, char** argv) {
  if (argc != 2) {
    printf("please specify a package name\n");
    return -1;
  }

  kernel *k = kernel_start();
  kernel_join(k);
}
