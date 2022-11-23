#include "Cogger.h"

using namespace CoggerLibrary;

Cogger::Cogger(std::string contextName, std::string filePath) {
  ContextName = contextName;
  if (filePath == "none") {
    LogToFile = false;
    FilePath = "";
  }
  DefaultLogType = LogTypes::Debug;
}

void Cogger::_PrintLevel(LogTypes logLevel) {
  switch(logLevel) {
    case LogTypes::Debug:
      printf(" [Debug]");
      break;
    case LogTypes::Warning:
      printf(" [Warning]");
      break;
    case LogTypes::Error:
      printf(" [Error]");
      break;
    case LogTypes::Info:
      printf(" [Info]");
      break;
  }
}

void Cogger::_PrintSender(std::string sender) {
  printf(" [%s] ", sender.c_str());
}

void Cogger::LogLn(std::string message, LogTypes level, std::string sender) {
  if (!IsPartialLog) {
    _PrintLevel(level);
    _PrintSender(sender);
    printf("%s\n", message.c_str());
  }
}

void Cogger::BeginGroup(std::string groupName) {
  LogGroupHeaderLength = groupName.length() + 3;
  IsLogGroup = true;
  for(auto i=0;i != LogGroupHeaderLength;++i) {
    printf("-");
  }
  printf("\n");
  printf("%s ->\n", groupName.c_str());
  for(auto i=0;i != LogGroupHeaderLength;++i) {
    printf("-");
  }
  printf("\n");
}

void Cogger::EndGroup() {
  if (IsLogGroup) {
    for(auto i=0;i != LogGroupHeaderLength;++i) {
      printf("-");
    }
    printf("\n");
  }
}

void Cogger::BeginLogLn(std::string message, LogTypes level, std::string sender) {
  if (!IsPartialLog) {
    _PrintLevel(level);
    _PrintSender(sender);
    printf("%s...", message.c_str());
  }
  IsPartialLog = true;
}

void Cogger::EndLogLn(std::string endMessage) {
  if (IsPartialLog) {
    printf("%s\n", endMessage.c_str());
  }
  IsPartialLog = false;
}