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
        set_color(default_color);
        print("Logger initialized.\n");
    }
    Logger::Logger(int default_color, const char* initialization_message)
    {
        set_color(default_color);
        print(initialization_message);
    }
    
    Logger::~Logger()
    {
    }

    void Logger::set_color(int ANSI_color_code)
    {
        default_color = ANSI_color_code;
    }

    void Logger::print(const char* text) const
    {
        printf("\033[%dm%s", default_color, text);
    }
    void Logger::print(int color, const char* text) const
    {
        printf("\033[%dm%s", color, text);
    }

    void Logger::print_int(int number) const
    {
        printf("\033[%dm%d", default_color, number);
    }

    void Logger::print_float(float number) const
    {
        printf("\033[%dm%f", default_color, number);
    }

    void Logger::print_array(vector_2d* content, int rows) const
    {
        print("(\n");
        for (int i = 0; i < rows; ++i)
        {
            print("  ( ");
            print_float(content[i].x);
            print(", ");
            print_float(content[i].y);
            print(" )\n");
        }
        print(")\n");
    }
}
