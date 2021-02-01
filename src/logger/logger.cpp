#include "logger.h"


namespace FakeEngine
{
    Logger::Logger()
    {
    }
    Logger::Logger(const char* initialization_message)
    {
        print(initialization_message);
        print("\n");
    }
    Logger::Logger(int default_color)
    {
        set_color(default_color);
    }
    Logger::Logger(int default_color, const char* initialization_message)
    {
        set_color(default_color);
        print(initialization_message);
        print("\n");
    }
    
    Logger::~Logger()
    {
    }

    void Logger::print_array(vector_2d* content, int rows) const
    {
        printl();
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("           [vector_2d]");
    }
    void Logger::print_array(vector_3d* content, int rows) const
    {
        printl();
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("                     [vector_3d]");
    }
    void Logger::print_array(vector_4d* content, int rows) const
    {
        printl();
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("                               [vector_4d]");
    }
}
