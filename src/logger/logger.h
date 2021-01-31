#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "types.h"


// List of ANSI color codes
#define FAKELOGGER_NORMAL (0)
#define FAKELOGGER_RED (91)
#define FAKELOGGER_GREEN (92)
#define FAKELOGGER_YELLOW (93)
#define FAKELOGGER_BLUE (94)
#define FAKELOGGER_VIOLET (95)
#define FAKELOGGER_CYAN (96)


namespace FakeEngine
{
    class Logger
    {
      private:
        int default_color;
      public:
        Logger();
        Logger(const char* initialization_message);
        Logger(int default_color);
        Logger(int default_color, const char* initialization_message);
        ~Logger();
        void set_color(int color);
        void print(const char* text) const;
        void print(int color, const char* text) const;
        void print_int(int number) const;
        void print_float(float number) const;
        void print_array(vector_2d* content, int rows) const;
    };
}
