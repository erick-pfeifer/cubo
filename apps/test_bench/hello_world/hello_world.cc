
#include "hello_world/hello_world.h"

#include "gpio/gpio_wrapper.h"
#include "pw_chrono/system_clock.h"
#include "pw_thread/sleep.h"

namespace hello_world {

using namespace std::chrono_literals;


void HelloWorldThread::Run() {
  while(true) {
    gpio::ToggleBoardLedPin();
    pw::this_thread::sleep_for(pw::chrono::SystemClock::duration{1s});
  }
  }

}  // namespace hello_world