
#include "hello_world/hello_world.h"

#include <string_view>

#include "pw_chrono/system_clock.h"
#include "pw_digital_io/digital_io.h"
#include "pw_status/status_with_size.h"
#include "pw_thread/sleep.h"

namespace hello_world {

using namespace std::chrono_literals;

pw::StatusWithSize HelloWorldThread::SaySomething(std::string_view s) {
  return pw::StatusWithSize{pw::OkStatus(), s.size()};
}

void HelloWorldThread::Run() {
  pw::chrono::SystemClock::duration period{500ms};
  while (true) {
    gpio_led_.SetState(pw::digital_io::State::kActive).IgnoreError();
    pw::this_thread::sleep_for(period);
    gpio_led_.SetState(pw::digital_io::State::kInactive).IgnoreError();
    pw::this_thread::sleep_for(period);
  }
}

}  // namespace hello_world