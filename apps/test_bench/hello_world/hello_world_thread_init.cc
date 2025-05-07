#include <cstddef>

#include "hello_world/hello_world.h"

#include "FreeRTOS.h"
#include "pw_thread/detached_thread.h"
#include "pw_thread/thread.h"
#include "pw_thread/context.h"
#include "pw_thread_freertos/context.h"
#include "pw_thread_freertos/options.h"

namespace hello_world {


void Init() {
  static HelloWorldThread thread_instance;

  static constexpr size_t kStackSizeInWords = 1024;
  static pw::thread::freertos::StaticContextWithStack<kStackSizeInWords> context;

  static constexpr auto options =
      pw::thread::freertos::Options()
          .set_name("HelloWorld")
          .set_static_context(context)
          .set_priority(tskIDLE_PRIORITY + 1);

  pw::thread::DetachedThread(options, thread_instance);
}
}  // namespace hello_world