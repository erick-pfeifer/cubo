#include "gpio_wrapper/gpio.h"

#include "peripheral/port/plib_port.h"
#include "same54p20a.h"

namespace gpio {
namespace {

bool GetBoardPinState() { return BTN_BOARD_Get() != 0; }

void SetDbgPin(bool state) { state ? DBG_Set() : DBG_Clear(); }
bool GetDbgPin() { return DBG_Get() != 0; }

void SetBoardLedPin(bool state) { state ? LED_Set() : LED_Clear(); }
bool GetBoardLedPin() { return LED_Get() != 0; }

void SetPinState(const Pin pin, const bool state) {
  // TODO - Use Microchip's PLIB and pin numbers, to replace this switch
  // statement.
  switch (pin) {
    case Pin::kDebug: {
      SetDbgPin(state);
      break;
    }
    case Pin::kLed: {
      SetBoardLedPin(state);
      break;
    }
    default:
      // TODO - Add error handling for trying to modify input pins.
      return;
  }
}

bool GetPinState(const Pin pin) {
  // TODO - Use Microchip's PLIB and pin numbers, to replace this switch
  // statement.
  switch (pin) {
    case Pin::kDebug: {
      return GetDbgPin();
      break;
    }
    case Pin::kLed: {
      return GetBoardLedPin();
      break;
    }
    case Pin::kSwitch: {
      return GetBoardPinState();
    }
    default:
      // TODO - Add error handling for trying to modify input pins.
      return false;
  }
}
}  // namespace

void PinStateWrapper::Set(const bool state) { SetPinState(pin_, state); }

bool PinStateWrapper::Get() { return GetPinState(pin_); }

}  // namespace gpio