
#include "definitions.h"
#include "peripheral/port/plib_port.h"
#include "pw_status/status.h"

namespace bench {
  pw::Status Foo() {
    return pw::OkStatus();
  }
}

int main() {
  SYS_Initialize(nullptr);
  bench::Foo().IgnoreError();
  while(true) {
    LED_Clear();
  }
  return 0;
}
