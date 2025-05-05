
#include "peripheral/systick/plib_systick.h"


extern "C" void configureTimerForRunTimeStats(void) {}

extern "C" unsigned long getRunTimeCounterValue(void) {
  return SYSTICK_GetTickCounter();
}