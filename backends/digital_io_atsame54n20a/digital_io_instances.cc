
#include "digital_io_atsame54n20a/digital_io.h"
#include "digital_io_atsame54n20a/digital_io_type.h"
#include "gpio_wrapper/gpio.h"
#include "pw_digital_io/digital_io.h"

namespace digital_io_atsame54n20a {

pw::digital_io::DigitalInOut& GetLedInstance() {
  static gpio::PinStateWrapper pin(gpio::Pin::kLed);
  static Config config{
      .pin = pin,
      .direction = Direction::kOutput,
      .polarity = Polarity::kNegative,
  };

  static Gpio led_instance(config);
  return led_instance;
}

}  // namespace digital_io_atsame54n20a