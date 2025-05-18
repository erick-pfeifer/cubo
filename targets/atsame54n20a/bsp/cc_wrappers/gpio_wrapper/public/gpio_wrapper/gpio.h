#pragma once

#include <cstdint>

#include "gpio_wrapper/gpio_type.h"

namespace gpio {

enum class Pin : uint8_t {
  kDebug,
  kLed,
  kSwitch,
};

class PinStateWrapper : public PinState {
 public:
  PinStateWrapper(const Pin pin) : pin_(pin) {}

  void Set(const bool state) override;
  bool Get() override;

 private:
  const Pin pin_;
};

}  // namespace gpio
