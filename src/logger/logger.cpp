#include "logger.h"


namespace FakeEngine
{    
    using namespace std;

    Logger::Logger()
    {
        print("Logger initialized.\n");
    }
    Logger::Logger(const char* initialization_message)
    {
        print(initialization_message);
    }
    Logger::Logger(int default_color)
    {
        set_default_color(default_color);
        print("Logger initialized.\n");
    }
    Logger::Logger(int default_color, const char* initialization_message)
    {
        set_default_color(default_color);
        print(initialization_message);
    }
    
    Logger::~Logger()
    {
    }

    void Logger::set_default_color(int ANSI_color_code)
    {
        default_color = ANSI_color_code;
    }

    void Logger::set_current_output_color(int color)
    {
        printf("\033[%dm", color);
    }

    void Logger::print(const char* text) const
    {
        printf("\033[%dm%s", default_color, text);
    }
    void Logger::print(int color, const char* text) const
    {
        printf("\033[%dm%s", color, text);
    }
}
