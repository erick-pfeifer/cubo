#pragma once

#include "pw_thread/thread_core.h"

namespace hello_world {

class HelloWorldThread : public pw::thread::ThreadCore {
 private:
  void Run() override;
};

void Init();

}  // namespace hello_world