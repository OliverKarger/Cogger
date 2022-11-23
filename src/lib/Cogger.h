#ifndef COGGER_H
#define COGGER_H

#ifdef WIN32
  #include <string>
#endif

#ifndef WIN32
  #include <string.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "LogTypes.h"

namespace CoggerLibrary {
  class Cogger {
  private:
    /**
     * @brief Context Name
     */
    std::string ContextName;

    /**
     * @brief Log File Path
     * only used if LogToFile is set to true
     */
    std::string FilePath;

    /**
     * @brief Default Log Level
     * 
     */
    LogTypes DefaultLogType;
    
    /**
     * @brief Logging to File enabled
     * 
     */
    bool LogToFile;

    /**
     * @brief Current Logging Group Name
     * only used if IsLogGroup is set to true
     */
    std::string CurrentGroupName;

    /**
     * @brief Logging Group is active
     * 
     */
    bool IsLogGroup;

    /**
     * @brief Length of Log Group Header/Name
     * 
     */
    int LogGroupHeaderLength;

    /**
     * @brief Set to true if BeginLogLn is called, set to false when EndLogLn is called 
     * Blocks any new Logging if set to true
     */
    bool IsPartialLog;

    /**
     * @brief Helper Method to print LogLevel
     * 
     * @param logLevel Log Level 
     */
    void _PrintLevel(LogTypes logLevel);

    /**
     * @brief Helper Method to print Log Sender 
     * 
     * @param sender Log Sender
     */
    void _PrintSender(std::string sender);
  public:
    /**
     * @brief Construct a new Cogger object
     * 
     * @param contextName Name of current Logging Context
     * @param filePath Log File Out Path [optional]
     */
    Cogger(std::string contextName, std::string filePath = "none");

    /**
     * @brief Write Log and go to next Line
     * 
     * @param message Log Message
     * @param level Log Level [optional]
     * @param sender Log Sender [optional]
     */
    void LogLn(std::string message, LogTypes level = LogTypes::Debug, std::string sender = "System");

    /**
     * @brief Begin Logging Group
     * 
     * @param groupName Group Name
     */
    void BeginGroup(std::string groupName);

    /**
     * @brief End Logging Group
     * 
     */
    void EndGroup();

    /**
     * @brief Begin Log Line
     * 
     * @param message Log Message
     * @param level Log Level [optional]
     * @param sender Log Sender [optional]
     * @example Log Message: Starting Application... DONE <- Done is Printed when EndLogLn() is called
     */
    void BeginLogLn(std::string message, LogTypes level = LogTypes::Debug, std::string sender = "System");

    /**
     * @brief Closes log Line
     * 
     */
    void EndLogLn(std::string endMessage = "Done");

  };
}

#endif