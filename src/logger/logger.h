#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>


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
        void set_default_color(int color);
        static void set_current_output_color(int color);
        void print(const char* text) const;
        void print(int color, const char* text) const;
        template<typename T>
        inline void print_multiple(std::vector<T> content_list) const
        {
            for (int i = 0; i < content_list.size(); ++i)
                std::cout << content_list[i];
        }
    };
}
