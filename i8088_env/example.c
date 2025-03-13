#include "libtvb.h"
volatile int a = 0;
void __attribute__((section(".entry"))) start() {
  init();
  for (int i = 0; i < 100; i++) {
    a++;
  }
  while (1) {
  }
}
