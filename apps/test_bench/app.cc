#include "pw_status/status.h"

namespace bench {
  pw::Status Foo() {
    return pw::Status::NotFound();
  }
}