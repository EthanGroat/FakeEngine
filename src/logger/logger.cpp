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

    void Logger::fprint(const char* format_string, ...) const
    {
        va_list args; va_start(args, format_string);
        char fs_buff[FAKELOGGER_INTERNAL_FORMATSTRING_BUFFER_SIZE];
        vsprintf(fs_buff, format_string, args);
        va_end(args);
        print(fs_buff);
    }
    void Logger::fprintl(const char* format_string, ...) const
    {
        va_list args; va_start(args, format_string);
        char fs_buff[FAKELOGGER_INTERNAL_FORMATSTRING_BUFFER_SIZE];
        vsprintf(fs_buff, format_string, args);
        va_end(args);
        print(fs_buff);
        printl();
    }

    void Logger::print_array(vector_2d* content, int rows) const
    {
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("           [vector_2d]");
    }
    void Logger::print_array(vector_3d* content, int rows) const
    {
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("                     [vector_3d]");
    }
    void Logger::print_array(vector_4d* content, int rows) const
    {
        for (int i = 0; i < rows; ++i)
            print_vector(content[i]);
        printl("                               [vector_4d]");
    }

    void Logger::print_event(Event* event) const
    {
        fprint("%s | id: %08x", event->get_event_type_name(), event->signature());
        print(" | payload: ");
        for (int i=0; i<EVENT_PAYLOAD_LENGTH; ++i)
            fprint("%c", event->payload()[i]);
        print(" (0x");
        for (int i=0; i<EVENT_PAYLOAD_LENGTH; ++i)
            fprint(" %x", event->payload()[i]);
        printl(")");
    }

    void Logger::print_event(Event event) const
    {
        Event* tmp_event_ptr = &event;
        print_event(tmp_event_ptr);
    }
}
