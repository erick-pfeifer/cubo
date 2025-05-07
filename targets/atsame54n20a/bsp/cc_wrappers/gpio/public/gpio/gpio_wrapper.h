#pragma once

namespace gpio {

/**
 * @brief Get the board Pin State.
 *
 * @return true
 * @return false
 */
bool GetBoardPinState();

/**
 * @brief Set the debug pin state
 *
 * @param state True/False for high/low states.
 */
void SetDbgPin(bool state);

/**
 * @brief Set the Board LED Pin.
 *
 * @param state True/False for high/low states.
 */
void SetBoardLedPin(bool state);

/**
 * @brief Toggle the Board LED Pin.
 *
 */
void ToggleBoardLedPin();

}  // namespace gpio
