
// Functions needed when configGENERATE_RUN_TIME_STATS is on.
extern "C" void configureTimerForRunTimeStats(void) {}
extern "C" unsigned long getRunTimeCounterValue(void) {
  // TODO - Provide proper runtime counter value.
  return 0;
}