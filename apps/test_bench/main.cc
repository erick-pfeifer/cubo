#include "definitions.h"
#include "FreeRTOS.h"
#include "task.h"
#include "hello_world/hello_world.h"


int main() {
  SYS_Initialize(nullptr);
  // TODO - Create auto initialization of apps with intrusive list registration.
  hello_world::Init();
  vTaskStartScheduler();
  return 0;
}
