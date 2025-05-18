#pragma once

namespace gpio {

class PinState {
 public:
  PinState() = default;
  virtual ~PinState() = default;

  virtual void Set(const bool state) = 0;
  virtual bool Get() = 0;
};
}  // namespace gpio
