#pragma once

#include <string_view>

#include "pw_digital_io/digital_io.h"
#include "pw_status/status_with_size.h"
#include "pw_thread/thread_core.h"

namespace hello_world {

class HelloWorldThread : public pw::thread::ThreadCore {
 public:
  HelloWorldThread(pw::digital_io::DigitalInOut& gpio_led)
      : gpio_led_(gpio_led) {}

  pw::StatusWithSize SaySomething(std::string_view s);

 private:
  pw::digital_io::DigitalInOut& gpio_led_;

  void Run() override;
};

void Init();

}  // namespace hello_world