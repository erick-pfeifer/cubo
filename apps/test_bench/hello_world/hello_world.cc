#include "hello_world/hello_world.h"

#include "definitions.h"
#include "peripheral/port/plib_port.h"
#include "pw_status/status.h"
#include "FreeRTOS.h"
#include "pw_thread/detached_thread.h"
#include "pw_thread/thread.h"
#include "pw_thread/context.h"
#include "pw_thread_freertos/context.h"
#include "pw_thread_freertos/options.h"

namespace hello_world {
namespace {

static constexpr size_t kStackSizeInWords = 1024;
static pw::thread::freertos::StaticContextWithStack<kStackSizeInWords> context;
const pw::thread::Options& CreateThreadOptions() {
  static constexpr auto options =
      pw::thread::freertos::Options()
          .set_name("HelloWorld")
          .set_static_context(context)
          .set_priority(tskIDLE_PRIORITY + 1);
  return options;
}
}  // namespace

void HelloWorldMain() {
  while(true) {
    LED_Toggle();
  }
}


void Init() {
 pw::thread::DetachedThread(CreateThreadOptions(), HelloWorldMain);
}
}  // namespace hello_world