#pragma once

#include "digital_io_atsame54n20a/digital_io_type.h"
#include "pw_digital_io/digital_io.h"

namespace digital_io_atsame54n20a {

class Gpio : public pw::digital_io::DigitalInOut {
 public:
  Gpio(Config& config, bool enabled = true)
      : config_(config), enabled_(enabled) {}

 private:
  pw::Status DoEnable(bool enable) override;
  pw::Status DoSetState(pw::digital_io::State level) override;
  pw::Result<pw::digital_io::State> DoGetState() override;

  Config& config_;
  bool enabled_;
};

}  // namespace digital_io_atsame54n20a