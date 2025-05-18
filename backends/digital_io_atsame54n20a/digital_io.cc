
#include "pw_digital_io/digital_io.h"

#include "digital_io_atsame54n20a/digital_io.h"
#include "digital_io_atsame54n20a/digital_io_type.h"
#include "pw_status/status.h"

namespace digital_io_atsame54n20a {

pw::Status Gpio::DoEnable(bool enable) {
  enabled_ = enable;
  return pw::OkStatus();
}

pw::Status Gpio::DoSetState(pw::digital_io::State level) {
  if (config_.direction == Direction::kInput) {
    return pw::Status::InvalidArgument();
  }

  if (enabled_ == false) {
    return pw::Status::Internal();
  }

  switch (level) {
    case pw::digital_io::State::kActive: {
      config_.pin.Set(config_.polarity == Polarity::kPositive);
      break;
    }
    case pw::digital_io::State::kInactive: {
      config_.pin.Set(config_.polarity == Polarity::kNegative);
      break;
    }
    default:
      return pw::Status::Internal();
  }
  return pw::OkStatus();
}

pw::Result<pw::digital_io::State> Gpio::DoGetState() {
  if (enabled_ == false) {
    return pw::Status::Internal();
  }

  bool state = (config_.polarity == Polarity::kPositive) ? config_.pin.Get()
                                                         : (!config_.pin.Get());
  return state ? pw::digital_io::State::kActive
               : pw::digital_io::State::kInactive;
}

}  // namespace digital_io_atsame54n20a