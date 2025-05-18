#include <cstddef>

#include "FreeRTOS.h"
#include "digital_io_atsame54n20a/digital_io_instances.h"
#include "hello_world/hello_world.h"
#include "pw_thread/context.h"
#include "pw_thread/detached_thread.h"
#include "pw_thread/thread.h"
#include "pw_thread_freertos/context.h"
#include "pw_thread_freertos/options.h"

namespace hello_world {

void Init() {
  static HelloWorldThread thread_instance(
      digital_io_atsame54n20a::GetLedInstance());

  static constexpr size_t kStackSizeInWords = 1024;
  static pw::thread::freertos::StaticContextWithStack<kStackSizeInWords>
      context;

  static constexpr auto options = pw::thread::freertos::Options()
                                      .set_name("HelloWorld")
                                      .set_static_context(context)
                                      .set_priority(tskIDLE_PRIORITY + 1);

  pw::thread::DetachedThread(options, thread_instance);
}
}  // namespace hello_world