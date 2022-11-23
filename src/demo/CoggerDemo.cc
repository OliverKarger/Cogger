#include <stdio.h>

#include "../lib/Cogger.h"

using namespace CoggerLibrary;

int main() {
  Cogger logger("Cogger Demo");
  
  logger.LogLn("Simple Log Line with Default Arguments");
  logger.LogLn("Simple Log Line with Error Level", LogTypes::Error);
  logger.LogLn("Simple Log Line with Error Level and custom Sender", LogTypes::Debug, "CoggerDemo");

  logger.BeginLogLn("Partial Log Line, started");
  logger.EndLogLn();

  logger.BeginGroup("Logging Group");
  logger.LogLn("Log 1");
  logger.LogLn("Log 1");
  logger.LogLn("Log 1");
  logger.LogLn("Log 1");
  logger.EndGroup();

  return 0;
}