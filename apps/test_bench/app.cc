
#include "definitions.h"
#include "peripheral/port/plib_port.h"
#include "pw_status/status.h"

namespace bench {
  pw::Status Foo() {
    return pw::Status::NotFound();
  }
}

int main() {
  SYS_Initialize(nullptr);
  bench::Foo().IgnoreError();
  while(true) {
    DBG_Toggle();
  }
  return 0;
}