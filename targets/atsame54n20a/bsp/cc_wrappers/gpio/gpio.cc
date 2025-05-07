#include "gpio/gpio_wrapper.h"
#include "peripheral/port/plib_port.h"
#include "same54p20a.h"

namespace gpio {

bool GetBoardPinState() { return BTN_BOARD_Get() != 0; }

void SetDbgPin(bool state) { state ? DBG_Set() : DBG_Clear(); }

void SetBoardLedPin(bool state) { state ? LED_Set() : LED_Clear(); }

void ToggleBoardLedPin() { LED_Toggle(); }

}  // namespace gpio