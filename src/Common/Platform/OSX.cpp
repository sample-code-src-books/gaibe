#include "OSX.h"

void Sleep(U64 ms)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
