#pragma once

#include "gpio_wrapper/gpio_type.h"

namespace digital_io_atsame54n20a {

enum class Direction : uint8_t {
  kInput,
  kOutput,
};

enum class Polarity : uint8_t {
  kPositive,
  kNegative,
};

struct Config {
  // TODO - Add more configs to replace the initialization from Microchip's MCC,
  // with our own, for each GPIO.
  gpio::PinState& pin;
  Direction direction;
  Polarity polarity;
};

}  // namespace digital_io_atsame54n20a