#ifndef LOGGER_H
#define LOGGER_H
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <ostream>
#include <ctype.h>
typedef std::string string;
class Logger
{
    string _filePath;
    std::ofstream _fp;

public:
    //if set to true, the logfiles are indexed via time
    Logger(bool useTime = false);
    ~Logger();
    void log(string outputString);
};

Logger::Logger(bool useTime)
{
    if (!useTime)
    {
        _filePath = "./logFile.txt";
    }
    else
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%r", &tstruct);
        _filePath = string(buf);
        _filePath = "./" + _filePath + ".txt";
    }
    _fp.open(_filePath);
    if (_fp.is_open())
    {
        _fp << "started loging here \n";
    }
    else
    {
        printf("failure opening log file \n");
    }
}

Logger::~Logger()
{
    //close the _fp
    _fp.close();
}
void Logger::log(string outputString)
{
    _fp << outputString;
}

#endif